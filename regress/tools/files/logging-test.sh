#! /bin/sh
# $NetBSD: logging-test.sh,v 1.1 2019/03/22 20:56:16 rillig Exp $

# Up to March 2019, the command logging for the wrapped tools didn't properly
# quote the command line arguments. This meant the logging did not reflect
# the actual tool command line.

set -eu

mydir=`dirname "$0"`
. "${mydir}/tests.subr"

tools_log="./tools.log"
nopath_log="./nopath.log"

rm -f "$tools_log" "$nopath_log"

TOOLS_WRAPPER_LOG="$tools_log"
export TOOLS_WRAPPER_LOG

# Forcibly call the echo from the tools directory. This tool is wrapped and
# logged.
(exec echo "begin" "*" "*" "*" "end")

unset TOOLS_WRAPPER_LOG

# usage: assert_file_equals $filename <<EOF ... EOF
assert_file_equals() {
	actual=`cat "$1"`
	expected=`cat`
	assert_equal "$1" "$expected" "$actual"
}

sed 's,/.*/\.tools/,WRKDIR/.tools/,' < "$tools_log" > "$nopath_log"

assert_file_equals "$nopath_log" <<EOF
[*] WRKDIR/.tools/bin/echo begin * * * end
<.> echo  begin tools.log tools.log tools.log end
EOF
# FIXME: the above output is not quoted correctly.
# The tools.log should not appear there.
