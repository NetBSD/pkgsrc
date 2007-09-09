#! /bin/sh
# $NetBSD: tar-test.sh,v 1.1 2007/09/09 08:01:45 rillig Exp $
#

set -e

mydir=`dirname "$0"`
. "${mydir}/tests.subr"

#
# Functions specific for the tar testsuite.
#

# none.

#
# The actual test.
#

# tar must support the -z option.
#
testcase_start "-z"
echo "data" > file
tar cfz archive.tar.gz file
