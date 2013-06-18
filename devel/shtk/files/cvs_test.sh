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

shtk_import cvs


MOCK_CVSROOT=":local:$(pwd)/cvsroot"


# Creates a local CVS repository with a variety of modules.
#
# \param repository Path to the repository to create.
# \param ... Modules to create.
init_cvsroot() {
    local repository="${1}"; shift

    atf_check -o ignore -e ignore cvs -d "${repository}" init

    for module in "${@}"; do
        mkdir module
        cd module
        echo "first revision" >"file-in-${module}"
        cvs -d "${repository}" import -m "Import." "${module}" VENDOR_TAG \
            release_tag
        cd -
        rm -rf module
    done
}


atf_test_case fetch
fetch_body() {
    init_cvsroot "${MOCK_CVSROOT}" src

    shtk_cvs_fetch "${MOCK_CVSROOT}" src "" first
    grep "first revision" first/file-in-src >/dev/null \
        || atf_fail "Unexpected version found"

    cp -rf first second
    echo "second revision" >second/file-in-src
    ( cd second && cvs commit -m "Second commit." )

    shtk_cvs_fetch "${MOCK_CVSROOT}" src "" first
    grep "second revision" first/file-in-src >/dev/null \
        || atf_fail "Unexpected version found"
}


atf_test_case checkout__same_name
checkout__same_name_body() {
    init_cvsroot "${MOCK_CVSROOT}" first second
    shtk_cvs_checkout "${MOCK_CVSROOT}" first "" $(pwd)/a/b/c/first
    [ -f a/b/c/first/file-in-first ] || atf_fail "Files not checked out"
    if [ -f a/b/c/second/file-in-second ]; then
        atf_fail "Unexpected module checked out"
    fi
}


atf_test_case checkout__different_name
checkout__different_name_body() {
    init_cvsroot "${MOCK_CVSROOT}" first second
    shtk_cvs_checkout "${MOCK_CVSROOT}" first "" $(pwd)/a/b/c/second
    [ -f a/b/c/second/file-in-first ] || atf_fail "Files not checked out"
}


atf_test_case checkout__already_exists
checkout__already_exists_body() {
    mkdir usr/src
    if ( shtk_cvs_checkout "${MOCK_CVSROOT}" src "" $(pwd)/usr/src ) >out 2>err
    then
        atf_fail "Checkout succeeded, but should not"
    else
        grep "Cannot checkout into $(pwd)/usr/src.*exists" err >/dev/null \
            || atf_fail "Expected error message not found"
    fi
}


atf_test_case checkout__permission_denied
checkout__permission_denied_head() {
    atf_set "require.user" "unprivileged"
}
checkout__permission_denied_body() {
    init_cvsroot "${MOCK_CVSROOT}" src
    mkdir usr
    chmod 555 usr
    if ( shtk_cvs_checkout "${MOCK_CVSROOT}" src "" $(pwd)/usr/src ) >out 2>err
    then
        atf_fail "Checkout succeeded, but should not"
    else
        grep "Failed to create $(pwd)/usr/src" err >/dev/null \
            || atf_fail "Expected error message not found"
    fi
}


atf_test_case checkout__cvs_fails
checkout__cvs_fails_body() {
    init_cvsroot "${MOCK_CVSROOT}" src
    if ( shtk_cvs_checkout "${MOCK_CVSROOT}" src "foo" $(pwd)/usr/src ) >out 2>err
    then
        atf_fail "Checkout succeeded, but should not"
    else
        grep "CVS checkout failed" err >/dev/null \
            || atf_fail "Expected error message not found"
    fi
}


atf_test_case update__ok
update__ok_body() {
    init_cvsroot "${MOCK_CVSROOT}" first second

    cvs -d "${MOCK_CVSROOT}" checkout first
    mv first copy
    cvs -d "${MOCK_CVSROOT}" checkout first

    shtk_cvs_update "${MOCK_CVSROOT}" "" first
    grep "first revision" first/file-in-first >/dev/null \
        || atf_fail "Unexpected version found"

    echo "second revision" >copy/file-in-first
    ( cd copy && cvs commit -m "Second commit." )

    shtk_cvs_update "${MOCK_CVSROOT}" "" first
    grep "second revision" first/file-in-first >/dev/null \
        || atf_fail "Unexpected version found"
}


atf_test_case update__resume_checkout
update__resume_checkout_body() {
    init_cvsroot "${MOCK_CVSROOT}" first

    cvs -d "${MOCK_CVSROOT}" checkout first
    mv first copy

    mkdir -p first/.cvs-checkout/first
    mv copy/CVS first/.cvs-checkout/first
    rm -rf copy

    shtk_cvs_update "${MOCK_CVSROOT}" "" first
    grep "first revision" first/file-in-first >/dev/null \
        || atf_fail "Unexpected version found"
}


atf_test_case update__does_not_exist
update__does_not_exist_body() {
    if ( shtk_cvs_update "${MOCK_CVSROOT}" "" src ) >out 2>err; then
        atf_fail "Update succeeded, but should not"
    else
        grep "Cannot update src; .*not exist" err >/dev/null \
            || atf_fail "Expected error message not found"
    fi
}


atf_test_case update__cvs_fails
update__cvs_fails_body() {
    init_cvsroot "${MOCK_CVSROOT}" src
    cvs -d "${MOCK_CVSROOT}" checkout src
    if ( shtk_cvs_update "${MOCK_CVSROOT}" "foo" src ) >out 2>err; then
        atf_fail "Update succeeded, but should not"
    else
        grep "CVS update failed" err >/dev/null \
            || atf_fail "Expected error message not found"
    fi
}


atf_init_test_cases() {
    atf_add_test_case fetch

    atf_add_test_case checkout__same_name
    atf_add_test_case checkout__different_name
    atf_add_test_case checkout__already_exists
    atf_add_test_case checkout__permission_denied
    atf_add_test_case checkout__cvs_fails

    atf_add_test_case update__ok
    atf_add_test_case update__resume_checkout
    atf_add_test_case update__does_not_exist
    atf_add_test_case update__cvs_fails
}
