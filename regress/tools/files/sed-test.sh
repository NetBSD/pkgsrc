#! /bin/sh
# $NetBSD: sed-test.sh,v 1.1 2006/09/20 07:39:55 rillig Exp $
#

set -e

mydir=`dirname "$0"`
. "${mydir}/tests.subr"

#
# Functions specific for the "sed" testsuite.
#

# usage: sed_test <testname> <input> <expected-output> <args...>
sed_test() {
	testname=$1; input=$2; expected=$3; shift 3;

	testcase_start "${testname}"
	output=`sed "$@" <<EOF
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

#
# Make sure that sed(1) can handle character classes.
#
sed_test "[[:character classes:]]" \
	"hello${nl}foo bar" \
	"hello" \
	-e "/[[:space:]]/d"
