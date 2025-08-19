#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> arr(n), bi(n);
    long long sumai = 0, sumbi = 0;

    for (int i = 0; i < n; i++) {
        cin >> arr[i] >> bi[i];
        sumai += arr[i];
        sumbi += bi[i];
    }

   
    if (sumbi > m) {
        cout << -1;
        return 0;
    }

   
    if (sumai <= m) {
        cout << 0;
        return 0;
    }

    vector<int> dif(n);
    for (int i = 0; i < n; i++) {
        dif[i] = arr[i] - bi[i];
    }

    sort(dif.begin(), dif.end(), greater<int>());

    long long current = sumai;
    int count = 0;
    for (int i = 0; i < n; i++) {
        current -= dif[i];
        count++;
        if (current <= m) {
            cout << count;
            return 0;
        }
    }

    cout << -1;
    return 0;
}
