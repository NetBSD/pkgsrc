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

# No imports: we can assume the bootstrap code to be present.


# Creates a "mock" module for shtk_import.
#
# \post SHTK_MODULESDIR is adjusted to point to our test directory.
create_mock_module() {
    mkdir -p modules
    cat >modules/mock.subr <<EOF
if [ -z "\${mock_value}" ]; then
    mock_value=1
else
    mock_value="\$((\${mock_value} + 1))"
fi
EOF
    SHTK_MODULESDIR="$(pwd)/modules"
}


atf_test_case import__ok
import__ok_body() {
    create_mock_module
    [ -z "${mock_value}" ] || atf_fail "mock_value already defined"
    shtk_import mock
    atf_check_equal 1 "${mock_value}"
}


atf_test_case import__idempotent
import__idempotent_body() {
    create_mock_module
    [ -z "${mock_value}" ] || atf_fail "mock_value already defined"
    shtk_import mock
    atf_check_equal 1 "${mock_value}"
    shtk_import mock
    atf_check_equal 1 "${mock_value}"
}


atf_test_case import__not_found
import__not_found_body() {
    SHTK_MODULESDIR=$(pwd)
    if ( shtk_import abcde ) >out 2>err; then
        atf_fail "import of a non-existent module succeeded"
    else
        cat >experr <<EOF
base_test: E: Cannot load module abcde; tried $(pwd)/abcde.subr
EOF
        atf_check -o file:experr cat err
    fi
}


atf_init_test_cases() {
    atf_add_test_case import__ok
    atf_add_test_case import__idempotent
    atf_add_test_case import__not_found
}
