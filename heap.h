//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    void push(int idx, int weightArr[]) {
        // TODO: insert index at end of heap, restore order using upheap()
        data[size]=idx; //puts the new node at the end
        size++;
        upheap(size-1, weightArr); //restores heap order

    }

    int pop(int weightArr[]) {
        // TODO: remove and return smallest index
        // Replace root with last element, then call downheap()
        if (size ==0) { // if heap is empty
            return -1;
        }
        int smallestIndex = data[0];
        data[0] = data[size - 1]; //moves last element to root
        size--; //decrease heap size bc you removed a element
        if (size>0) {
            downheap(0, weightArr); //downheap to restore heap order
        }
        return smallestIndex;
    }

    void upheap(int pos, int weightArr[]) {
        // TODO: swap child upward while smaller than parent
        while (pos > 0) {
            int parentPos = (pos - 1)/2;
            if (weightArr[data[pos]] < weightArr[data[parentPos]]) { //if child < parent, swap them
                swap(data[pos], data[parentPos]); //built-in function
                pos = parentPos;
            }
           else{
               break;
           } //continue until pos ==0 or heap order is correct
        }
    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
        int small = pos;
        while (true) {
            int leftChild = 2*pos +1;
            int rightChild = 2*pos +2;
            if (leftChild < size && weightArr[data[leftChild]] < weightArr[data[small]]) {
                small = leftChild;
            }
            if (rightChild < size && weightArr[data[rightChild]] < weightArr[data[small]]) {
                small = rightChild;
            }
            if (small == pos) { //if pos is already smallest
                break;
            }
            swap(data[pos], data[small]);
            pos = small;
        }
    }

};

#endif