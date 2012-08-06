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


atf_test_case global_progname
global_progname_body() {
    [ "${Utils_ProgName}" = utils_test ] \
        || atf_fail "Invalid value in Utils_ProgName"
}


atf_test_case error
error_body() {
    if ( utils_error "This is" "a message"; echo "not seen" ) >out 2>err; then
        atf_fail "utils_error did not exit with an error"
    else
        grep "utils_test: E: This is a message" err >/dev/null \
            || atf_fail "Expected error message not found"
        [ ! -s out ] || atf_fail "Unexpected output in stdout"
    fi
}


atf_test_case info
info_body() {
    ( utils_info "This is" "a message"; echo "continuing" ) >out 2>err
    grep "utils_test: I: This is a message" err >/dev/null \
        || atf_fail "Expected info message not found"
    grep "continuing" out >/dev/null || atf_fail "Execution aborted"
}


atf_test_case usage_error
usage_error_body() {
    if ( utils_usage_error "This is" "a message"; echo "not seen" ) >out 2>err
    then
        atf_fail "utils_usage_error did not exit with an error"
    else
        grep "utils_test: E: This is a message" err >/dev/null \
            || atf_fail "Expected error message not found"
        grep "Type 'man utils_test' for help" err >/dev/null \
            || atf_fail "Expected instructional message not found"
        [ ! -s out ] || atf_fail "Unexpected output in stdout"
    fi
}


atf_test_case warning
warning_body() {
    ( utils_warning "This is" "a message"; echo "continuing" ) >out 2>err
    grep "utils_test: W: This is a message" err >/dev/null \
        || atf_fail "Expected info message not found"
    grep "continuing" out >/dev/null || atf_fail "Execution aborted"
}


atf_test_case run__ok
run__ok_body() {
    cat >helper.sh <<EOF
#! /bin/sh
echo "This exits cleanly:" "\${@}"
exit 0
EOF
    chmod +x helper.sh

    utils_run ./helper.sh one two three >out 2>err \
        || atf_fail "Got an unexpected error code"

    cat >expout <<EOF
This exits cleanly: one two three
EOF
    atf_check -o file:expout cat out

    cat >experr <<EOF
utils_test: I: Running './helper.sh one two three' in $(pwd)
utils_test: I: Command finished successfully
EOF
    atf_check -o file:experr cat err
}


atf_test_case run__fail
run__fail_body() {
    cat >helper.sh <<EOF
#! /bin/sh
echo "This exits with an error:" "\${@}"
exit 42
EOF
    chmod +x helper.sh

    code=0
    utils_run ./helper.sh one two three >out 2>err || code="${?}"
    [ ${code} -eq 42 ] \
        || atf_fail "Did not get the expected error code; got ${code}"

    cat >expout <<EOF
This exits with an error: one two three
EOF
    atf_check -o file:expout cat out

    cat >experr <<EOF
utils_test: I: Running './helper.sh one two three' in $(pwd)
utils_test: W: Command failed with code 42
EOF
    atf_check -o file:experr cat err
}


atf_test_case contains__yes
contains__yes_body() {
    items="bar foo baz"
    utils_contains foo ${items} || atf_fail "Element not found in list"
}


atf_test_case contains__no
contains__no_body() {
    items="bar foo baz"
    ! utils_contains fo ${items} || atf_fail "Element found in list"
}


atf_test_case filter__no_items
filter__no_items_body() {
    atf_check_equal "" "$(utils_filter '*')"
}


atf_test_case filter__no_results
filter__no_results_body() {
    items="abc a1 foo a2 a3 bar"
    atf_check_equal "" "$(utils_filter '*a' ${items})"
}


atf_test_case filter__some_results
filter__some_results_body() {
    items="abc a1 foo a2 a3 bar"
    atf_check_equal "a1 a2 a3" "$(utils_filter 'a[0-9]*' ${items})"
}


atf_init_test_cases() {
    atf_add_test_case global_progname

    atf_add_test_case error
    atf_add_test_case info
    atf_add_test_case warning

    atf_add_test_case usage_error

    atf_add_test_case run__ok
    atf_add_test_case run__fail

    atf_add_test_case contains__yes
    atf_add_test_case contains__no

    atf_add_test_case filter__no_items
    atf_add_test_case filter__no_results
    atf_add_test_case filter__some_results
}
