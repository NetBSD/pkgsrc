#! /bin/sh
# $NetBSD: awk-test.sh,v 1.8 2006/05/31 13:10:49 rillig Exp $
#

set -e

mydir=`dirname "$0"`
. "${mydir}/tests.subr"

#
# Functions specific for the awk testsuite.
#

# usage: test_assignment <testname> <input> <expected-output>
test_assignment() {
	testcase_start "$1"
	o=`echo "" | awk '{print var}' var="$2"`
	assert_equal "$1" "$3" "${o}"
}

# usage: test_passline <testname> <input>
test_passline() {
	testcase_start "$1"
	o=`awk '{print}' <<EOF
$2
EOF
`
	assert_equal "$1" "$2" "${o}"
}

#
# The actual test.
#

#
# Assignment of variables from the command line. The Solaris
# /usr/bin/awk does not conform to the POSIX specification, but passes
# the right hand side of the assignment uninterpreted. It fails the
# cmd.3 test case. The "for" loop makes sure that awk can handle strings
# of 4096 bytes length.
#
test_assignment "cmd.1" \
	"foo" "foo"
test_assignment "cmd.2" \
	"foo bar baz" "foo bar baz"
test_assignment "cmd.3" \
	"CPPFLAGS=\\\"-Dfoo=bar\\\"" "CPPFLAGS=\"-Dfoo=bar\""
line="a"
for i in 0 1 2 3 4 5 6 7 8 9 10 11 12; do
	test_assignment "cmd.2^${i}" "${line}" "${line}"
	line="${line}${line}"
done

#
# Passing strings from stdin to stdout. awk should be able to handle at
# least 2^12 characters per line.
#
# Solaris 9 /usr/bin/awk: 2559 bytes
# Solaris 9 /usr/bin/nawk: 6144 bytes
#
line="a"
for i in 0 1 2 3 4 5 6 7 8 9 10 11 12; do
	test_passline "line.2^${i}" "${line}"
	line="${line}${line}"
done
