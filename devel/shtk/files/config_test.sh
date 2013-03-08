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

shtk_import config


atf_test_case is_valid__true
is_valid__true_body() {
    shtk_config_init VAR1 VAR3
    for var in VAR1 VAR3; do
        shtk_config_is_valid "${var}" || atf_fail "${var} not found"
    done
}


atf_test_case is_valid__false
is_valid__false_body() {
    shtk_config_init VAR1 VAR3
    for var in VAR11 VAR2 VAR; do
        if shtk_config_is_valid "${var}"; then
            atf_fail "${var} found but was not registered"
        fi
    done
}


atf_test_case has__true__empty
has__true__empty_body() {
    shtk_config_init TESTVAR
    shtk_config_set TESTVAR ""
    shtk_config_has TESTVAR || atf_fail "Expected variable not found"
}


atf_test_case has__true__not_empty
has__true__not_empty_body() {
    shtk_config_init TESTVAR
    shtk_config_set TESTVAR "foo"
    shtk_config_has TESTVAR || atf_fail "Expected variable not found"
}


atf_test_case has__false
has__false_body() {
    shtk_config_init TESTVAR
    if shtk_config_has TESTVAR; then
        atf_fail "Unexpected variable found"
    fi
}


atf_test_case get__ok__empty
get__ok__empty_body() {
    shtk_config_init TESTVAR

    shtk_config_set TESTVAR ""
    [ -z "$(shtk_config_get TESTVAR)" ] || atf_fail "Failed to query value"
}


atf_test_case get__ok__not_empty
get__ok__not_empty_body() {
    shtk_config_init TESTVAR

    shtk_config_set TESTVAR some-value
    [ "$(shtk_config_get TESTVAR)" = some-value ] || atf_fail "Failed to query value"
}


atf_test_case get__undefined_variable
get__undefined_variable_body() {
    shtk_config_init TESTVAR

    if ( shtk_config_get TESTVAR ) >out 2>err; then
        atf_fail "Got unset variable successfully"
    else
        grep "Required configuration variable TESTVAR not set" err >/dev/null \
            || atf_fail "Expected error message not found"
    fi
}


atf_test_case get_bool__true
get_bool__true_body() {
    shtk_config_init TESTVAR

    for value in yes Yes true True; do
        shtk_config_set TESTVAR "${value}"
        shtk_config_get_bool TESTVAR || atf_fail "Expected true, but got false"
    done
}


atf_test_case get_bool__false
get_bool__false_body() {
    shtk_config_init TESTVAR

    for value in no No false False; do
        shtk_config_set TESTVAR "${value}"
        if shtk_config_get_bool TESTVAR; then
            atf_fail "Expected false, but got true"
        fi
    done
}


atf_test_case get_bool__undefined_variable
get_bool__undefined_variable_body() {
    shtk_config_init TESTVAR

    if shtk_config_get_bool TESTVAR; then
        atf_fail "Expected false, but got true"
    fi
}


atf_test_case get_bool__invalid_value
get_bool__invalid_value_body() {
    shtk_config_init TESTVAR

    shtk_config_set TESTVAR not-a-boolean
    if ( shtk_config_get_bool TESTVAR ) >out 2>err; then
        atf_fail "Got invalid boolean value successfully"
    else
        grep "Invalid boolean value in variable TESTVAR" err >/dev/null \
            || atf_fail "Expected error message not found"
    fi
}


atf_test_case get_default__defined__empty
get_default__defined__empty_body() {
    shtk_config_init TESTVAR
    shtk_config_set TESTVAR ""
    [ "$(shtk_config_get_default TESTVAR 'foo')" = "" ] \
        || atf_fail "Did not fetch defined value"
}


atf_test_case get_default__defined__not_empty
get_default__defined__not_empty_body() {
    shtk_config_init TESTVAR
    shtk_config_set TESTVAR "bar"
    [ "$(shtk_config_get_default TESTVAR 'foo')" = "bar" ] \
        || atf_fail "Did not fetch defined value"
}


atf_test_case get_default__default__empty
get_default__default__empty_body() {
    shtk_config_init TESTVAR
    [ "$(shtk_config_get_default TESTVAR '')" = "" ] \
        || atf_fail "Did not fetch default value"
}


atf_test_case get_default__default__not_empty
get_default__default__not_empty_body() {
    shtk_config_init TESTVAR
    [ "$(shtk_config_get_default TESTVAR 'foo')" = "foo" ] \
        || atf_fail "Did not fetch default value"
}


atf_test_case set__ok
set__ok_body() {
    shtk_config_init TESTVAR

    shtk_config_set TESTVAR some-value
    [ "${shtk_config_var_TESTVAR}" = some-value ] || atf_fail "Failed to set value"
}


atf_test_case set__unknown_variable
set__unknown_variable_body() {
    shtk_config_init TESTVAR

    if ( shtk_config_set TESTVAR2 some-value ) >out 2>err; then
        atf_fail "Set unknown variable successfully"
    else
        grep "Unknown configuration variable TESTVAR2" err >/dev/null \
            || atf_fail "Expected error message not found"
    fi
}


atf_test_case unset__ok
unset__ok_body() {
    shtk_config_init TESTVAR

    shtk_config_var_TESTVAR=some-value
    shtk_config_unset TESTVAR
    [ "${shtk_config_var_TESTVAR-unset}" = unset ] \
        || atf_fail "Failed to unset variable"
}


atf_test_case unset__unknown_variable
unset__unknown_variable_body() {
    shtk_config_init TESTVAR

    if ( shtk_config_unset TESTVAR2 ) >out 2>err; then
        atf_fail "Unset unknown variable successfully"
    else
        grep "Unknown configuration variable TESTVAR2" err >/dev/null \
            || atf_fail "Expected error message not found"
    fi
}


atf_test_case load__filter_variables
load__filter_variables_body() {
    shtk_config_init Z VAR1 EMPTY

    cat >test.conf <<EOF
A=foo
Z=bar
VAR1="some text"
VAR2="some other text"
EOF

    shtk_config_load $(pwd)/test.conf || atf_fail "Failed to load test configuration"

    [ "${shtk_config_var_Z}" = bar ] || \
        atf_fail "Z not found in configuration"
    [ "${shtk_config_var_VAR1}" = "some text" ] || \
        atf_fail "VAR1 not found in configuration"

    [ "${shtk_config_var_EMPTY-has_not_been_set}" = has_not_been_set ] || \
        atf_fail "Undefined variable set, but should not have been"

    [ "${shtk_config_var_A-unset}" = unset ] || \
        atf_fail "A set in configuration, but not expected"
    [ "${shtk_config_var_VAR2-unset}" = unset ] || \
        atf_fail "VAR2 set in configuration, but not expected"
}


atf_test_case load__allow_undefine
load__allow_undefine_body() {
    shtk_config_init UNDEFINE

    cat >test.conf <<EOF
UNDEFINE=
EOF

    shtk_config_set UNDEFINE "remove me"
    shtk_config_load $(pwd)/test.conf || atf_fail "Failed to load test configuration"
    if shtk_config_has UNDEFINE; then
        atf_fail "Undefine attempt from configuration did not work"
    fi
}


atf_test_case load__current_directory
load__current_directory_body() {
    shtk_config_init A

    cat >test.conf <<EOF
A=foo
EOF

    shtk_config_load test.conf || atf_fail "Failed to load test configuration"

    [ "${shtk_config_var_A}" = foo ] || \
        atf_fail "A not found in configuration"
}


atf_test_case load__missing_file
load__missing_file_body() {
    if ( shtk_config_load missing.conf ) >out 2>err; then
        atf_fail "Missing configuration file load succeeded"
    else
        grep "Configuration file missing.conf does not exist" err >/dev/null \
            || atf_fail "Expected error message not found"
    fi
}


atf_test_case load__invalid_file
load__invalid_file_body() {
    echo "this file is invalid" >invalid.conf

    if ( shtk_config_load invalid.conf ) >out 2>err; then
        atf_fail "Invalid configuration file load succeeded"
    else
        cat err
        grep "Failed to load configuration file invalid.conf" err >/dev/null \
            || atf_fail "Expected error message not found"
    fi
}


atf_test_case override__ok_before_load
override__ok_before_load_body() {
    shtk_config_init VAR1 VAR2

    cat >test.conf <<EOF
VAR1="override me"
VAR2="do not override me"
EOF

    shtk_config_override "VAR1=new value"
    shtk_config_load test.conf || atf_fail "Failed to load test configuration"

    [ "${shtk_config_var_VAR1}" = "new value" ] || atf_fail "Override failed"
    [ "${shtk_config_var_VAR2}" = "do not override me" ] \
        || atf_fail "Overrode more than one variable"
}


atf_test_case override__not_ok_after_load
override__not_ok_after_load_body() {
    shtk_config_init VAR1 VAR2

    cat >test.conf <<EOF
VAR1="override me"
VAR2="do not override me"
EOF

    shtk_config_load test.conf || atf_fail "Failed to load test configuration"
    shtk_config_override "VAR1=new value"

    [ "${shtk_config_var_VAR1}" = "override me" ] \
        || atf_fail "Override succeeded, but it should not have"
    [ "${shtk_config_var_VAR2}" = "do not override me" ] \
        || atf_fail "Overrode more than one variable"
}


atf_test_case override__invalid_format
override__invalid_format_body() {
    for arg in foo =bar ''; do
        if ( shtk_config_override "${arg}" ) >out 2>err; then
            atf_fail "Invalid configuration override ${arg} succeeded"
        else
            cat err
            grep "Invalid configuration override ${arg}" err >/dev/null \
                || atf_fail "Expected error message not found"
        fi
    done
}


atf_test_case override__unknown_variable
override__unknown_variable_body() {
    shtk_config_init Z VAR1
    for arg in A=b VAR2=d; do
        if ( shtk_config_override "${arg}" ) >out 2>err; then
            atf_fail "Invalid configuration override ${arg} succeeded"
        else
            cat err
            grep "Unknown configuration variable ${var}" err >/dev/null \
                || atf_fail "Expected error message not found"
        fi
    done
}


atf_test_case run_hook__ok
run_hook__ok_body() {
    shtk_config_init VAR1 VAR2 VAR3
    shtk_config_set VAR1 "first"
    shtk_config_set VAR3 "third"

    test_hook() {
        echo "ARGS=${*}"
        echo "VAR1=${VAR1:-unset}"
        echo "VAR2=${VAR2:-unset}"
        echo "VAR3=${VAR3:-unset}"
    }

    VAR1=ignore-this; VAR2=ignore-this; VAR3=ignore-this
    shtk_config_run_hook test_hook arg1 arg2 >out 2>err

    cat >expout <<EOF
ARGS=arg1 arg2
VAR1=first
VAR2=unset
VAR3=third
EOF
    atf_check -o file:expout cat out
    atf_check -o empty cat err
}


atf_test_case run_hook__fail
run_hook__fail_body() {
    shtk_config_init VAR1
    shtk_config_set VAR1 "first"

    test_hook() {
        echo "VAR1=${VAR1:-unset}"
        false
    }

    (
        if shtk_config_run_hook test_hook >out 2>err; then
            atf_fail "Hook failure did not report an error"
        fi
    )

    cat >expout <<EOF
VAR1=first
EOF
    cat >experr <<EOF
EOF
    atf_check -o file:expout cat out
    grep "The hook test_hook returned an error" err >/dev/null \
        || atf_fail "Expected error message not found"
}


atf_init_test_cases() {
    atf_add_test_case is_valid__true
    atf_add_test_case is_valid__false

    atf_add_test_case has__true__empty
    atf_add_test_case has__true__not_empty
    atf_add_test_case has__false

    atf_add_test_case get__ok__empty
    atf_add_test_case get__ok__not_empty
    atf_add_test_case get__undefined_variable

    atf_add_test_case get_bool__true
    atf_add_test_case get_bool__false
    atf_add_test_case get_bool__undefined_variable
    atf_add_test_case get_bool__invalid_value

    atf_add_test_case get_default__defined__empty
    atf_add_test_case get_default__defined__not_empty
    atf_add_test_case get_default__default__empty
    atf_add_test_case get_default__default__not_empty

    atf_add_test_case set__ok
    atf_add_test_case set__unknown_variable

    atf_add_test_case unset__ok
    atf_add_test_case unset__unknown_variable

    atf_add_test_case load__filter_variables
    atf_add_test_case load__allow_undefine
    atf_add_test_case load__current_directory
    atf_add_test_case load__missing_file
    atf_add_test_case load__invalid_file

    atf_add_test_case override__ok_before_load
    atf_add_test_case override__not_ok_after_load
    atf_add_test_case override__invalid_format
    atf_add_test_case override__unknown_variable

    atf_add_test_case run_hook__ok
    atf_add_test_case run_hook__fail
}
