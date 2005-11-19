#! /bin/sh
# $NetBSD: awk-test.sh,v 1.1.1.1 2005/11/19 21:27:06 rillig Exp $
#

set -e

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
test_assignment "CPPFLAGS=\\\"-Dfoo=bar\\\"" "CPPFLAGS=\"-Dfoo=bar\""
