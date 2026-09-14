#include <stdio.h>
#include <string.h>

#define MAX 100

struct Patient {
    char name[20];
    int priority;
};

struct Patient queue[MAX];
int size = 0;

void addPatient(char name[], int priority) {
    strcpy(queue[size].name, name);
    queue[size].priority = priority;
    size++;
}

void treatNext() {
    if (size == 0) {
        printf("No patients waiting.\n");
        return;
    }

    int minIndex = 0;

    for (int i = 1; i < size; i++) {
        if (queue[i].priority < queue[minIndex].priority) {
            minIndex = i;
        }
    }

    printf("Treating: %s (Priority %d)\n",
           queue[minIndex].name,
           queue[minIndex].priority);

    for (int i = minIndex; i < size - 1; i++) {
        queue[i] = queue[i + 1];
    }

    size--;
}

int main() {

    addPatient("P1", 3);
    addPatient("P2", 1);
    addPatient("P3", 2);
    addPatient("P4", 1);
    addPatient("P5", 3);
    addPatient("P6", 2);

    printf("Treatment Order:\n");

    treatNext();
    treatNext();

    addPatient("Emergency", 1);

    printf("\nNew Emergency Patient Added!\n");

    while (size > 0) {
        treatNext();
    }

    return 0;
}
