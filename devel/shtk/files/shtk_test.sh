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


atf_test_case build__defaults
build__defaults_body() {
    cat >script.sh <<EOF
shtk_import cli

main() {
    shtk_cli_info "It works"
}
EOF

    atf_check shtk build script.sh

    cat >experr <<EOF
script: I: It works
EOF
    atf_check -e file:experr ./script
}


atf_test_case build__mflag__explicit
build__mflag__explicit_body() {
    cat >script.sh <<EOF
shtk_import cli

my_main() {
    shtk_cli_info "Print this"
}

main() {
    shtk_cli_info "Don't print this"
}
EOF

    atf_check shtk build -m my_main script.sh

    cat >experr <<EOF
script: I: Print this
EOF
    atf_check -e file:experr ./script
}


atf_test_case build__mflag__empty
build__mflag__empty_body() {
    cat >script.sh <<EOF
shtk_import cli

shtk_cli_info "Outside of main"

main() {
    shtk_cli_info "Don't print this"
}
EOF

    atf_check shtk build -m '' script.sh

    cat >experr <<EOF
script: I: Outside of main
EOF
    atf_check -e file:experr ./script
}


atf_test_case build__oflag__explicit
build__oflag__explicit_body() {
    cat >script.sh <<EOF
shtk_import cli

main() {
    shtk_cli_info "A string"
}
EOF
    atf_check shtk build -o first script.sh
    atf_check -e inline:'first: I: A string\n' ./first
}


atf_test_case build__oflag__stdin
build__oflag__stdin_body() {
    cat >script.sh <<EOF
shtk_import cli

main() {
    shtk_cli_info "A string"
}
EOF
    cat script.sh | atf_check shtk build -o second -
    atf_check -e inline:'second: I: A string\n' ./second
}


atf_test_case build__oflag__necessary
build__oflag__necessary_body() {
    touch script

    cat >experr <<EOF
shtk: E: Input file should end in .sh or you must specify -o
Type 'man shtk' for help
EOF
    atf_check -s exit:1 -e file:experr shtk build script
    echo "foo" | atf_check -s exit:1 -e file:experr shtk build -
}


atf_test_case build__sflag
build__sflag_body() {
    cat >script.sh <<EOF
We won't run this anyway.
EOF
    atf_check shtk build -s '/custom/interpreter' script.sh
    atf_check -o inline:'#! /custom/interpreter\n' head -n1 script
}


atf_test_case build__no_args
build__no_args_body() {
    cat >experr <<EOF
shtk: E: build takes one argument only
Type 'man shtk' for help
EOF
    atf_check -s exit:1 -e file:experr shtk build
}


atf_test_case build__too_many_args
build__too_many_args_body() {
    cat >experr <<EOF
shtk: E: build takes one argument only
Type 'man shtk' for help
EOF
    atf_check -s exit:1 -e file:experr shtk build foo bar
}


atf_test_case version__ok
version__ok_body() {
    atf_check -s exit:0 -o match:"shtk [0-9]+\.[0-9]+.*" shtk version
}


atf_test_case version__too_many_args
version__too_many_args_body() {
    cat >experr <<EOF
shtk: E: version does not take any arguments
Type 'man shtk' for help
EOF
    atf_check -s exit:1 -e file:experr shtk version foo
}


atf_test_case no_command
no_command_body() {
    cat >experr <<EOF
shtk: E: No command specified
Type 'man shtk' for help
EOF
    atf_check -s exit:1 -e file:experr shtk
}


atf_test_case unknown_command
unknown_command_body() {
    cat >experr <<EOF
shtk: E: Unknown command foo
Type 'man shtk' for help
EOF
    atf_check -s exit:1 -e file:experr shtk foo
}


atf_init_test_cases() {
    atf_add_test_case build__defaults
    atf_add_test_case build__mflag__explicit
    atf_add_test_case build__mflag__empty
    atf_add_test_case build__oflag__explicit
    atf_add_test_case build__oflag__stdin
    atf_add_test_case build__oflag__necessary
    atf_add_test_case build__sflag
    atf_add_test_case build__no_args
    atf_add_test_case build__too_many_args

    atf_add_test_case version__ok
    atf_add_test_case version__too_many_args

    atf_add_test_case no_command
    atf_add_test_case unknown_command
}
