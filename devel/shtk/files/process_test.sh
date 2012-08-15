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

shtk_import process


atf_test_case run__ok
run__ok_body() {
    cat >helper.sh <<EOF
#! /bin/sh
echo "This exits cleanly:" "\${@}"
exit 0
EOF
    chmod +x helper.sh

    shtk_process_run ./helper.sh one two three >out 2>err \
        || atf_fail "Got an unexpected error code"

    cat >expout <<EOF
This exits cleanly: one two three
EOF
    atf_check -o file:expout cat out

    cat >experr <<EOF
process_test: I: Running './helper.sh one two three' in $(pwd)
process_test: I: Command finished successfully
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
    shtk_process_run ./helper.sh one two three >out 2>err || code="${?}"
    [ ${code} -eq 42 ] \
        || atf_fail "Did not get the expected error code; got ${code}"

    cat >expout <<EOF
This exits with an error: one two three
EOF
    atf_check -o file:expout cat out

    cat >experr <<EOF
process_test: I: Running './helper.sh one two three' in $(pwd)
process_test: W: Command failed with code 42
EOF
    atf_check -o file:experr cat err
}


atf_init_test_cases() {
    atf_add_test_case run__ok
    atf_add_test_case run__fail
}
