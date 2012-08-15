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

shtk_import cli


# Saves the original value of argv[0] for testing purposes.
_Original_Arg0="${0}"


atf_test_case dirname
dirname_body() {
    atf_check_equal "$(dirname "${_Original_Arg0}")" "$(shtk_cli_dirname)"
}


atf_test_case progname
progname_body() {
    atf_check_equal "$(basename "${_Original_Arg0}")" "$(shtk_cli_progname)"
}


atf_test_case error
error_body() {
    if ( shtk_cli_error "This is" "a message"; echo "not seen" ) >out 2>err
    then
        atf_fail "shtk_cli_error did not exit with an error"
    else
        grep "cli_test: E: This is a message" err >/dev/null \
            || atf_fail "Expected error message not found"
        [ ! -s out ] || atf_fail "Unexpected output in stdout"
    fi
}


atf_test_case info
info_body() {
    ( shtk_cli_info "This is" "a message"; echo "continuing" ) >out 2>err
    grep "cli_test: I: This is a message" err >/dev/null \
        || atf_fail "Expected info message not found"
    grep "continuing" out >/dev/null || atf_fail "Execution aborted"
}


atf_test_case usage_error
usage_error_body() {
    if ( shtk_cli_usage_error "This is" "a message"; echo "not seen" ) >out 2>err
    then
        atf_fail "shtk_cli_usage_error did not exit with an error"
    else
        grep "cli_test: E: This is a message" err >/dev/null \
            || atf_fail "Expected error message not found"
        grep "Type 'man cli_test' for help" err >/dev/null \
            || atf_fail "Expected instructional message not found"
        [ ! -s out ] || atf_fail "Unexpected output in stdout"
    fi
}


atf_test_case warning
warning_body() {
    ( shtk_cli_warning "This is" "a message"; echo "continuing" ) >out 2>err
    grep "cli_test: W: This is a message" err >/dev/null \
        || atf_fail "Expected info message not found"
    grep "continuing" out >/dev/null || atf_fail "Execution aborted"
}


atf_init_test_cases() {
    atf_add_test_case dirname
    atf_add_test_case progname

    atf_add_test_case error
    atf_add_test_case info
    atf_add_test_case warning

    atf_add_test_case usage_error
}
