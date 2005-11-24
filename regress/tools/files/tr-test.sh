#! /bin/sh
# $NetBSD: tr-test.sh,v 1.2 2005/11/24 19:46:45 rillig Exp $
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
tr_test "eat-minus" \
	"describe-function" "describefunction" -d "-"
# The following test does not work on NetBSD 1.6.2.
#tr_test "eat-minus-d" \
#	"describe-function" "escribefunction" -d "-d"
tr_test "eat-d-minus" \
	"describe-function" "escribefunction" -d "d-"

s="0123456789abcdef"
s="$s$s$s$s$s$s$s$s$s$s$s$s$s$s$s$s"
s="$s$s$s$s$s$s$s$s$s$s$s$s$s$s$s$s"
s="$s$s$s$s$s$s$s$s$s$s$s$s$s$s$s$s"
f="ffffffffffffffff"
f="$f$f$f$f$f$f$f$f$f$f$f$f$f$f$f$f"
f="$f$f$f$f$f$f$f$f$f$f$f$f$f$f$f$f"

tr_test "65536" \
	"$s" "$f" -d "0-9a-e"
