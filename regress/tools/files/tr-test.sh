#! /bin/sh
# $NetBSD: tr-test.sh,v 1.1 2005/11/24 19:39:23 rillig Exp $
#

set -e

mydir=`dirname "$0"`
. "${mydir}/tests.subr"

#
# Functions specific for the tr testsuite.
#

# usage: tr_test <testname> <input> <expected-output> <args...>
tr_test() {
	testname=$1; input=$2; expected=$3; shift 3;

	testcase_start "${testname}"
	output=`tr "$@" <<EOF
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

tr_test "simple" \
	"foo" "baa" "fo" "ba"
tr_test "tolower" \
	"The Great Green Fox" "the great green fox" "A-Z" "a-z"
tr_test "eat-newlines" \
	"foo${nl}bar${nl}" "foobar" -d "\\n"
