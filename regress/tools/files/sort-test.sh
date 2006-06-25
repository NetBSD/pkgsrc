#! /bin/sh
# $NetBSD: sort-test.sh,v 1.1 2006/06/25 21:47:28 rillig Exp $
#

set -e

mydir=`dirname "$0"`
. "${mydir}/tests.subr"

#
# Functions specific for the "sort" testsuite.
#

# usage: sort_test <testname> <input> <expected-output> <args...>
sort_test() {
	testname=$1; input=$2; expected=$3; shift 3;

	testcase_start "${testname}"
	output=`sort "$@" <<EOF
$input
EOF
`
	assert_equal "${testname}" "${expected}" "${output}"
}

#
# The actual test.
#

nl="
"

sort_test "one line" \
	"text line 1" "text line 1"
sort_test "uppercase letters" \
	"A${nl}B${nl}C" "A${nl}B${nl}C"
sort_test "A < C < b" \
	"A${nl}b${nl}C" "A${nl}C${nl}b"
