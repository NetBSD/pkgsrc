#! @ATF_SH@
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


# Path to a local cvsroot for testing purposes.
MOCK_CVSROOT=":local:$(pwd)/cvsroot"


# Creates a fake program that records its invocations for later processing.
#
# The fake program, when invoked, will append its arguments to a commands.log
# file in the test case's work directory.
#
# \param binary The path to the program to create.
# \param delegate If set to 'yes', execute the real program afterwards.
create_mock_binary() {
    local binary="${1}"; shift
    local delegate=no
    [ ${#} -eq 0 ] || { delegate="${1}"; shift; }

    cat >"${binary}" <<EOF
#! /bin/sh

logfile="${HOME}/commands.log"
echo "Command: \${0##*/}" >>"\${logfile}"
echo "Directory: \$(pwd)" >>"\${logfile}"
for arg in "\${@}"; do
    echo "Arg: \${arg}" >>"\${logfile}"
done
    echo >>"\${logfile}"
EOF

    if [ "${delegate}" = yes ]; then
        cat >>"${binary}" <<EOF
PATH="${PATH}"
exec "\${0##*/}" "\${@}"
EOF
    fi

    chmod +x "${binary}"
}


# Creates a fake CVS repository with a src and an xsrc module.
#
# \param repository Path to the repository to create.
create_mock_cvsroot() {
    local repository="${1}"; shift

    atf_check -o ignore -e ignore cvs -d "${repository}" init

    mkdir src
    cd src
    create_mock_binary build.sh
    echo "first revision" >file-in-src
    cvs -d "${repository}" import -m "Import." src VENDOR_TAG release_tag
    cd -
    rm -rf src

    mkdir xsrc
    cd xsrc
    echo "first revision" >file-in-xsrc
    cvs -d "${repository}" import -m "Import." xsrc VENDOR_TAG release_tag
    cd -
    rm -rf xsrc
}


atf_test_case build__custom_dirs
build__custom_dirs_body() {
    create_mock_cvsroot "${MOCK_CVSROOT}"

    create_mock_binary cvs yes
    PATH="$(pwd):${PATH}"

    cat >test.conf <<EOF
BUILD_ROOT=$(pwd)/b
CVSROOT=${MOCK_CVSROOT}
RELEASEDIR=$(pwd)/r
SRCDIR=$(pwd)/s
XSRCDIR=$(pwd)/x
EOF

    atf_check -o save:stdout -e save:stderr sysbuild -c test.conf build

    cat >expout <<EOF
Command: cvs
Directory: ${HOME}/s/.cvs-checkout
Arg: -d${MOCK_CVSROOT}
Arg: -q
Arg: checkout
Arg: -P
Arg: src

Command: cvs
Directory: ${HOME}/x/.cvs-checkout
Arg: -d${MOCK_CVSROOT}
Arg: -q
Arg: checkout
Arg: -P
Arg: xsrc

Command: build.sh
Directory: ${HOME}/s
Arg: -D${HOME}/b/$(uname -m)/destdir
Arg: -M${HOME}/b/$(uname -m)/obj
Arg: -N2
Arg: -R${HOME}/r
Arg: -T${HOME}/b/$(uname -m)/tools
Arg: -U
Arg: -X${HOME}/x
Arg: -m$(uname -m)
Arg: -x
Arg: release

EOF
    atf_check -o file:expout cat commands.log
}


atf_test_case build__defaults
build__defaults_body() {
    create_mock_cvsroot "${MOCK_CVSROOT}"

    create_mock_binary cvs yes
    PATH="$(pwd):${PATH}"

    atf_check -o save:stdout -e save:stderr sysbuild \
        -c /dev/null -o CVSROOT="${MOCK_CVSROOT}" build

    cat >expout <<EOF
Command: cvs
Directory: ${HOME}/sysbuild/src/.cvs-checkout
Arg: -d${MOCK_CVSROOT}
Arg: -q
Arg: checkout
Arg: -P
Arg: src

Command: build.sh
Directory: ${HOME}/sysbuild/src
Arg: -D${HOME}/sysbuild/$(uname -m)/destdir
Arg: -M${HOME}/sysbuild/$(uname -m)/obj
Arg: -N2
Arg: -R${HOME}/sysbuild/release
Arg: -T${HOME}/sysbuild/$(uname -m)/tools
Arg: -U
Arg: -m$(uname -m)
Arg: release

EOF
    atf_check -o file:expout cat commands.log
}


atf_test_case build__remove_all
build__remove_all_body() {
    create_mock_cvsroot "${MOCK_CVSROOT}"
    mkdir sysbuild
    cd sysbuild
    atf_check -o ignore -e ignore cvs -d"${MOCK_CVSROOT}" checkout -P src
    cd -

    create_mock_binary cvs
    PATH="$(pwd):${PATH}"

    mkdir -p "sysbuild/$(uname -m)/destdir/a"
    mkdir -p "sysbuild/$(uname -m)/obj/b"
    mkdir -p "sysbuild/$(uname -m)/tools/c"
    mkdir -p "sysbuild/$(uname -m)/keep-me"

    atf_check -o save:stdout -e save:stderr sysbuild \
        -c /dev/null -o CVSROOT="${MOCK_CVSROOT}" build

    [ ! -d "sysbuild/$(uname -m)/destdir" ] || atf_fail "destdir not removed"
    [ ! -d "sysbuild/$(uname -m)/obj" ] || atf_fail "obj not removed"
    [ ! -d "sysbuild/$(uname -m)/tools" ] || atf_fail "tools not removed"
    [ -d "sysbuild/$(uname -m)/keep-me" ] || atf_fail "All of buildroot removed"
}


atf_test_case build__fast_mode
build__fast_mode_body() {
    create_mock_cvsroot "${MOCK_CVSROOT}"
    mkdir sysbuild
    cd sysbuild
    atf_check -o ignore -e ignore cvs -d"${MOCK_CVSROOT}" checkout -P src
    cd -

    create_mock_binary cvs
    PATH="$(pwd):${PATH}"

    mkdir -p "sysbuild/$(uname -m)/destdir/bin"
    mkdir -p "sysbuild/$(uname -m)/destdir/stand/$(uname -m)/1.2.3"

    atf_check -o save:stdout -e save:stderr sysbuild \
        -c /dev/null -o CVSROOT="${MOCK_CVSROOT}" build -f

    cat >expout <<EOF
Command: build.sh
Directory: ${HOME}/sysbuild/src
Arg: -D${HOME}/sysbuild/$(uname -m)/destdir
Arg: -M${HOME}/sysbuild/$(uname -m)/obj
Arg: -N2
Arg: -R${HOME}/sysbuild/release
Arg: -T${HOME}/sysbuild/$(uname -m)/tools
Arg: -U
Arg: -m$(uname -m)
Arg: -u
Arg: release

EOF
    atf_check -o file:expout cat commands.log

    [ -d "sysbuild/$(uname -m)/destdir/bin" ] \
        || atf_fail "Deleted a directory that should not have been deleted"
    [ ! -d "sysbuild/$(uname -m)/destdir/stand/$(uname -m)/1.2.3" ] \
        || atf_fail "Obsolete modules not deleted"
}


atf_test_case build__many_machines
build__many_machines_body() {
    create_mock_cvsroot "${MOCK_CVSROOT}"

    create_mock_binary cvs yes
    PATH="$(pwd):${PATH}"

    atf_check -o save:stdout -e save:stderr sysbuild \
        -c /dev/null -o CVSROOT="${MOCK_CVSROOT}" \
        -o MACHINES="amd64 macppc shark" -o NJOBS=2 build

    cat >expout <<EOF
Command: cvs
Directory: ${HOME}/sysbuild/src/.cvs-checkout
Arg: -d${MOCK_CVSROOT}
Arg: -q
Arg: checkout
Arg: -P
Arg: src

Command: build.sh
Directory: ${HOME}/sysbuild/src
Arg: -D${HOME}/sysbuild/amd64/destdir
Arg: -M${HOME}/sysbuild/amd64/obj
Arg: -N2
Arg: -R${HOME}/sysbuild/release
Arg: -T${HOME}/sysbuild/amd64/tools
Arg: -U
Arg: -j2
Arg: -mamd64
Arg: release

Command: build.sh
Directory: ${HOME}/sysbuild/src
Arg: -D${HOME}/sysbuild/macppc/destdir
Arg: -M${HOME}/sysbuild/macppc/obj
Arg: -N2
Arg: -R${HOME}/sysbuild/release
Arg: -T${HOME}/sysbuild/macppc/tools
Arg: -U
Arg: -j2
Arg: -mmacppc
Arg: release

Command: build.sh
Directory: ${HOME}/sysbuild/src
Arg: -D${HOME}/sysbuild/shark/destdir
Arg: -M${HOME}/sysbuild/shark/obj
Arg: -N2
Arg: -R${HOME}/sysbuild/release
Arg: -T${HOME}/sysbuild/shark/tools
Arg: -U
Arg: -j2
Arg: -mshark
Arg: release

EOF
    atf_check -o file:expout cat commands.log
}


atf_test_case build__with_x11
build__with_x11_body() {
    create_mock_cvsroot "${MOCK_CVSROOT}"

    create_mock_binary cvs yes
    PATH="$(pwd):${PATH}"

    atf_check -o save:stdout -e save:stderr sysbuild \
        -c /dev/null -o CVSROOT="${MOCK_CVSROOT}" \
        -o XSRCDIR="${HOME}/sysbuild/xsrc" build

    cat >expout <<EOF
Command: cvs
Directory: ${HOME}/sysbuild/src/.cvs-checkout
Arg: -d${MOCK_CVSROOT}
Arg: -q
Arg: checkout
Arg: -P
Arg: src

Command: cvs
Directory: ${HOME}/sysbuild/xsrc/.cvs-checkout
Arg: -d${MOCK_CVSROOT}
Arg: -q
Arg: checkout
Arg: -P
Arg: xsrc

Command: build.sh
Directory: ${HOME}/sysbuild/src
Arg: -D${HOME}/sysbuild/$(uname -m)/destdir
Arg: -M${HOME}/sysbuild/$(uname -m)/obj
Arg: -N2
Arg: -R${HOME}/sysbuild/release
Arg: -T${HOME}/sysbuild/$(uname -m)/tools
Arg: -U
Arg: -X${HOME}/sysbuild/xsrc
Arg: -m$(uname -m)
Arg: -x
Arg: release

EOF
    atf_check -o file:expout cat commands.log
}


atf_test_case build__some_args
build__some_args_body() {
    create_mock_cvsroot "${MOCK_CVSROOT}"

    create_mock_binary cvs yes
    PATH="$(pwd):${PATH}"

    atf_check -o save:stdout -e save:stderr sysbuild \
        -c /dev/null -o CVSROOT="${MOCK_CVSROOT}" build a foo b

    cat >expout <<EOF
Command: cvs
Directory: ${HOME}/sysbuild/src/.cvs-checkout
Arg: -d${MOCK_CVSROOT}
Arg: -q
Arg: checkout
Arg: -P
Arg: src

Command: build.sh
Directory: ${HOME}/sysbuild/src
Arg: -D${HOME}/sysbuild/$(uname -m)/destdir
Arg: -M${HOME}/sysbuild/$(uname -m)/obj
Arg: -N2
Arg: -R${HOME}/sysbuild/release
Arg: -T${HOME}/sysbuild/$(uname -m)/tools
Arg: -U
Arg: -m$(uname -m)
Arg: a
Arg: foo
Arg: b

EOF
    atf_check -o file:expout cat commands.log
}


atf_test_case config__builtins
config__builtins_body() {
    cat >expout <<EOF
BUILD_ROOT = ${HOME}/sysbuild
BUILD_TARGETS = release
CVSROOT = :ext:anoncvs@anoncvs.NetBSD.org:/cvsroot
CVSTAG is undefined
INCREMENTAL_BUILD = false
MACHINES = $(uname -m)
NJOBS is undefined
RELEASEDIR = ${HOME}/sysbuild/release
SRCDIR = ${HOME}/sysbuild/src
UPDATE_SOURCES = true
XSRCDIR is undefined
EOF
    atf_check -o file:expout sysbuild -c /dev/null config
}


atf_test_case config__path__components
config__path__components_body() {
    mkdir .sysbuild
    mkdir system
    export SYSBUILD_ETCDIR="$(pwd)/system"

    echo "BUILD_TARGETS=foo" >my-file
    atf_check -o match:"BUILD_TARGETS = foo" sysbuild -c ./my-file config
}


atf_test_case config__path__extension
config__path__extension_body() {
    mkdir .sysbuild
    mkdir system
    export SYSBUILD_ETCDIR="$(pwd)/system"

    echo "BUILD_TARGETS=bar" >my-file.conf
    atf_check -o match:"BUILD_TARGETS = bar" sysbuild -c my-file.conf config
}


atf_test_case config__name__system_directory
config__name__system_directory_body() {
    mkdir .sysbuild
    mkdir system
    export SYSBUILD_ETCDIR="$(pwd)/system"

    echo "BUILD_TARGETS='some value'" >system/foo.conf
    atf_check -o match:"BUILD_TARGETS = some value" sysbuild -c foo config
}


atf_test_case config__name__user_directory
config__name__user_directory_body() {
    mkdir .sysbuild
    mkdir system
    export SYSBUILD_ETCDIR="$(pwd)/system"

    echo "BUILD_TARGETS='some value'" >system/foo.conf
    echo "BUILD_TARGETS='other value'" >.sysbuild/foo.conf
    atf_check -o match:"BUILD_TARGETS = other value" sysbuild -c foo config
}


atf_test_case config__name__not_found
config__name__not_found_body() {
    mkdir .sysbuild
    mkdir system
    export SYSBUILD_ETCDIR="$(pwd)/system"

    cat >experr <<EOF
sysbuild: E: Cannot locate configuration named 'foobar'
Type 'man sysbuild' for help
EOF
    atf_check -s exit:1 -o empty -e file:experr sysbuild -c foobar config
}


atf_test_case config__overrides
config__overrides_body() {
    cat >custom.conf <<EOF
BUILD_ROOT=/tmp/test
CVSTAG=the-tag-override
EOF

    cat >expout <<EOF
BUILD_ROOT = /tmp/test
BUILD_TARGETS = release
CVSROOT = foo bar
CVSTAG = the-new-tag
INCREMENTAL_BUILD = false
MACHINES = $(uname -m)
NJOBS is undefined
RELEASEDIR = ${HOME}/sysbuild/release
SRCDIR is undefined
UPDATE_SOURCES = true
XSRCDIR is undefined
EOF
    atf_check -o file:expout sysbuild -c custom.conf -o CVSROOT="foo bar" \
        -o CVSTAG=the-new-tag -o SRCDIR= config
}


atf_test_case config__too_many_args
config__too_many_args_body() {
    cat >experr <<EOF
sysbuild: E: config does not take any arguments
Type 'man sysbuild' for help
EOF
    atf_check -s exit:1 -e file:experr sysbuild -c /dev/null config foo
}


atf_test_case fetch__checkout__src_only
fetch__checkout__src_only_body() {
    create_mock_cvsroot "${MOCK_CVSROOT}"
    cat >test.conf <<EOF
CVSROOT="${MOCK_CVSROOT}"
SRCDIR="$(pwd)/checkout/src"
XSRCDIR=
EOF

    atf_check -o ignore -e not-match:"xsrc" sysbuild -c test.conf fetch
    test -f checkout/src/file-in-src || atf_fail "src not checked out"
    test ! -d checkout/xsrc || atf_fail "xsrc checked out but not requested"
}


atf_test_case fetch__checkout__src_and_xsrc
fetch__checkout__src_and_xsrc_body() {
    create_mock_cvsroot "${MOCK_CVSROOT}"
    cat >test.conf <<EOF
CVSROOT="${MOCK_CVSROOT}"
SRCDIR="$(pwd)/checkout/src"
XSRCDIR="$(pwd)/checkout/xsrc"
EOF

    atf_check -o ignore -e ignore sysbuild -c test.conf fetch
    test -f checkout/src/file-in-src || atf_fail "src not checked out"
    test -f checkout/xsrc/file-in-xsrc || atf_fail "xsrc not checked out"
}


atf_test_case fetch__update__src_only
fetch__update__src_only_body() {
    create_mock_cvsroot "${MOCK_CVSROOT}"
    cat >test.conf <<EOF
CVSROOT="${MOCK_CVSROOT}"
SRCDIR="$(pwd)/checkout/src"
XSRCDIR=
EOF

    mkdir checkout
    cd checkout
    atf_check -o ignore -e ignore cvs -d"${MOCK_CVSROOT}" checkout -P src
    cd -

    cp -rf checkout/src src-copy
    cd src-copy
    echo "second revision" >file-in-src
    cvs commit -m "Second revision."
    cd -

    test -f checkout/src/file-in-src || atf_fail "src not present yet"
    if grep "second revision" checkout/src/file-in-src >/dev/null; then
        atf_fail "second revision already present"
    fi

    atf_check -o ignore -e not-match:"xsrc" sysbuild -c test.conf fetch

    grep "second revision" checkout/src/file-in-src >/dev/null \
        || atf_fail "src not updated"
    test ! -d checkout/xsrc || atf_fail "xsrc checked out but not requested"
}


atf_test_case fetch__update__src_and_xsrc
fetch__update__src_and_xsrc_body() {
    create_mock_cvsroot "${MOCK_CVSROOT}"
    cat >test.conf <<EOF
CVSROOT="${MOCK_CVSROOT}"
SRCDIR="$(pwd)/checkout/src"
XSRCDIR="$(pwd)/checkout/xsrc"
EOF

    mkdir checkout
    cd checkout
    atf_check -o ignore -e ignore cvs -d"${MOCK_CVSROOT}" checkout -P src xsrc
    cd -

    cp -rf checkout/src src-copy
    cd src-copy
    echo "second revision" >file-in-src
    cvs commit -m "Second revision."
    cd -

    cp -rf checkout/xsrc xsrc-copy
    cd xsrc-copy
    echo "second revision" >file-in-xsrc
    cvs commit -m "Second revision."
    cd -

    test -f checkout/src/file-in-src || atf_fail "src not present yet"
    if grep "second revision" checkout/src/file-in-src >/dev/null; then
        atf_fail "second revision already present"
    fi
    test -f checkout/xsrc/file-in-xsrc || atf_fail "xsrc not present yet"
    if grep "second revision" checkout/xsrc/file-in-xsrc >/dev/null; then
        atf_fail "second revision already present"
    fi

    atf_check -o ignore -e ignore sysbuild -c test.conf fetch

    grep "second revision" checkout/src/file-in-src >/dev/null \
        || atf_fail "src not updated"
    grep "second revision" checkout/xsrc/file-in-xsrc >/dev/null \
        || atf_fail "xsrc not updated"
}


atf_test_case fetch__too_many_args
fetch__too_many_args_body() {
    cat >experr <<EOF
sysbuild: E: fetch does not take any arguments
Type 'man sysbuild' for help
EOF
    atf_check -s exit:1 -e file:experr sysbuild -c /dev/null fetch foo
}


atf_test_case no_command
no_command_body() {
    cat >experr <<EOF
sysbuild: E: No command specified
Type 'man sysbuild' for help
EOF
    atf_check -s exit:1 -e file:experr sysbuild
}


atf_test_case unknown_command
unknown_command_body() {
    cat >experr <<EOF
sysbuild: E: Unknown command foo
Type 'man sysbuild' for help
EOF
    atf_check -s exit:1 -e file:experr sysbuild foo
}


atf_test_case unknown_flag
unknown_flag_body() {
    cat >experr <<EOF
sysbuild: E: Unknown option -Z
Type 'man sysbuild' for help
EOF
    atf_check -s exit:1 -e file:experr sysbuild -Z
}


atf_init_test_cases() {
    atf_add_test_case build__custom_dirs
    atf_add_test_case build__defaults
    atf_add_test_case build__remove_all
    atf_add_test_case build__fast_mode
    atf_add_test_case build__many_machines
    atf_add_test_case build__with_x11
    atf_add_test_case build__some_args

    atf_add_test_case config__builtins
    atf_add_test_case config__path__components
    atf_add_test_case config__path__extension
    atf_add_test_case config__name__system_directory
    atf_add_test_case config__name__user_directory
    atf_add_test_case config__name__not_found
    atf_add_test_case config__overrides
    atf_add_test_case config__too_many_args

    atf_add_test_case fetch__checkout__src_only
    atf_add_test_case fetch__checkout__src_and_xsrc
    atf_add_test_case fetch__update__src_only
    atf_add_test_case fetch__update__src_and_xsrc
    atf_add_test_case fetch__too_many_args

    atf_add_test_case no_command
    atf_add_test_case unknown_command
    atf_add_test_case unknown_flag
}
