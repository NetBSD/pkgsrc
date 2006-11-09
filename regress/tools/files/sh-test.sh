#! /bin/sh
# $NetBSD: sh-test.sh,v 1.1 2006/11/09 12:39:55 rillig Exp $
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

line="#define bindir \"/usr/bin\" /* bar */"
sh_assert_equals "removing C comments" "#define bindir \"/usr/bin\" " "${line%%/\**}"
