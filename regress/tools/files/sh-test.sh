#! /bin/sh
# $NetBSD: sh-test.sh,v 1.3 2018/12/05 19:01:40 rillig Exp $
#

set -e

mydir=`dirname "$0"`
. "${mydir}/tests.subr"

#
# Functions specific for the sh testsuite.
#

# usage: sh_test <testname> <input> <expected-output> <args...>
sh_test() {
	testname=$1; input=$2; expected=$3; shift 3;

	testcase_start "${testname}"
	output=`sh ${1+"$@"} <<EOF
$input
EOF
`
	assert_equal "${testname}" "${expected}" "${output}"
}

# usage: sh_assert_equals "testname" "expected" "got"
sh_assert_equals() {

	testcase_start "$1"
	assert_equal "$1" "$2" "$3"
}

#
# The actual test.
#

nl="
"

# If this test fails because the result is "#define bindir \"", the
# tested shell may be from NetBSD 7.0, which is known to have this bug.
# Since NetBSD 8, this bug is fixed. See https://gnats.netbsd.org/43469.
line="#define bindir \"/usr/bin\" /* bar */"
sh_assert_equals "removing C comments" "#define bindir \"/usr/bin\" " "${line%%/\**}"
