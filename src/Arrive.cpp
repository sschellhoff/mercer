/*
MIT License

Copyright (c) 2018 Sören Schellhoff

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "mercer/AI/Steering/Flee.hpp"
#include "mercer/Misc/VectorUtils.hpp"
#include <algorithm>

namespace mercer {

sf::Vector2f arrive(const sf::Vector2f &target_position, const sf::Vector2f &own_position, const sf::Vector2f &own_velocity, float max_speed, float deceleration) {
    sf::Vector2f to_target = target_position - own_position;
    auto distance = vectorLength(to_target);

    if(distance > 0.000001f) {
        auto speed = distance / deceleration;
        speed = std::min(speed, max_speed);

        sf::Vector2f desired_velocity = to_target * speed / distance;
        return desired_velocity - own_velocity;
    }

    return sf::Vector2f{0, 0};
}

}