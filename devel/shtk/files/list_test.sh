# Copyright 2012 Google Inc.
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are
# met:
#
# * Redistributions of source code must retain the above copyright
#   notice, this list of conditions and the following disclaimer.
# * Redistributions in binary form must reproduce the above copyright
#   notice, this list of conditions and the following disclaimer in the
#   documentation and/or other materials provided with the distribution.
# * Neither the name of Google Inc. nor the names of its contributors
#   may be used to endorse or promote products derived from this software
#   without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
# A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
# OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
# SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
# LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
# DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
# THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
# OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

shtk_import list


atf_test_case contains__yes
contains__yes_body() {
    items="bar foo baz"
    shtk_list_contains foo ${items} || atf_fail "Element not found in list"
}


atf_test_case contains__no
contains__no_body() {
    items="bar foo baz"
    ! shtk_list_contains fo ${items} || atf_fail "Element found in list"
}


atf_test_case filter__no_items
filter__no_items_body() {
    atf_check_equal "" "$(shtk_list_filter '*')"
}


atf_test_case filter__no_results
filter__no_results_body() {
    items="abc a1 foo a2 a3 bar"
    atf_check_equal "" "$(shtk_list_filter '*a' ${items})"
}


atf_test_case filter__some_results
filter__some_results_body() {
    items="abc a1 foo a2 a3 bar"
    atf_check_equal "a1 a2 a3" "$(shtk_list_filter 'a[0-9]*' ${items})"
}


atf_init_test_cases() {
    atf_add_test_case contains__yes
    atf_add_test_case contains__no

    atf_add_test_case filter__no_items
    atf_add_test_case filter__no_results
    atf_add_test_case filter__some_results
}
