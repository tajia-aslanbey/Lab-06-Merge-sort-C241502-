#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r) {
    int L[100], R[100], i, j, k;
    for (i = 0; i <= m - l; i++) L[i] = arr[l + i];
    for (j = 0; j < r - m; j++) R[j] = arr[m + 1 + j];
    for (i = j = 0, k = l; i <= m - l && j < r - m; k++)
        arr[k] = L[i] <= R[j] ? L[i++] : R[j++];
    while (i <= m - l) arr[k++] = L[i++];
    while (j < r - m) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = 7;

    cout << "Array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    mergeSort(arr, 0, n - 1);

    cout << "Sorted: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}
