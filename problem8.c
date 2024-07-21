#include <stdio.h>
 
// Function to find the smallest element in the unsorted part of the array
int findSmallest(int arr[], int start, int n) {
    int smallest = arr[start];
    int pos = start;
    for (int j = start + 1; j < n; j++) {
        if (arr[j] < smallest) {
            smallest = arr[j];
            pos = j;
        }
    }
    return pos;
}
 
// Function to perform selection sort
void selectionSort(int arr[], int n) {
    int i, pos, temp;
    for (i = 0; i < n - 1; i++) {
        // Find the position of the smallest element in the unsorted part of the array
        pos = findSmallest(arr, i, n);
        // Swap the found smallest element with the first element of the unsorted part
        temp = arr[i];
        arr[i] = arr[pos];
        arr[pos] = temp;
    }
}
 
// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
 
int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Unsorted array: \n");
    printArray(arr, n);
    
    selectionSort(arr, n);
    
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}