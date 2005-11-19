#! /bin/sh
# $NetBSD: awk-test.sh,v 1.2 2005/11/19 21:31:10 rillig Exp $
#

set -e

# usage: assert_equal <expected> <got>
assert_equal() {
	case $1 in
	"$2")	;;
	*)	echo "[assert_equal] expected \"$1\", got \"$2\"." 1>&2
		exit 1;;
	esac
}

# usage: test_assignment <input> <expected-output>
test_assignment() {
	o=`echo "" | awk '{print var}' var="$1"`
	assert_equal "$2" "${o}"
}

test_assignment "foo" "foo"
test_assignment "foo bar baz" "foo bar baz"
# The Solaris /usr/bin/awk does not conform to the POSIX specification,
# but passes the right hand side of the assignment uninterpreted.
test_assignment "CPPFLAGS=\\\"-Dfoo=bar\\\"" "CPPFLAGS=\"-Dfoo=bar\""
