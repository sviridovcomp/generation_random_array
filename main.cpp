#include <random>
#include <iostream>
#include <set>

int main() {
    size_t n = 0;
    std::cin >> n;

    int32_t x = 0;
    std::cin >> x;
    int32_t y = 0;
    std::cin >> y;

    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(x, y);

    std::vector<int32_t> buffer(n);

    for (auto &&i: buffer) {
        i = distrib(gen);
    }

    for (auto &&i: buffer) {
        std::cout << i << ' ';
    }

    std::cout << '\n';

    std::set<int32_t> unique(std::make_move_iterator(buffer.begin()), std::make_move_iterator(buffer.end()));

    for (auto &&i: unique) {
        std::cout << i << ' ';
    }
}