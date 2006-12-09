#! /bin/sh
# $NetBSD: test-transform.sh,v 1.1 2006/12/09 12:42:43 rillig Exp $
#
# NAME
#	test-transform - Test for a single-argument transformation plug-in
#
# SYNOPSIS
#	test-transform.sh transform-file arg...
#
# DESCRIPTION
#	test-transform builds up an environment like in the wrapper.sh
#	script and feeds the remaining arguments to the transformation
#	file.  It prints the result of the transformation on stdout,
#	suitable for manual checking.
#
# EXAMPLES
#	sh test-transform.sh transform-xlc-cc -E -Wall -dynamiclib
#

set -eu

wrapperdir=`dirname "$0"`
. "${wrapperdir}/../scripts/shell-lib"
. "${wrapperdir}/wrapper-subr.sh"

msg_log() {
	shift
	echo "[msg_log] $*"
}

debug_log="msg_log"
wrapperlog="stderr"

transformation_file="$1"; shift

for arg in "$@"; do
	split_arg=no
	addtocache=no
	. "./$transformation_file"
	echo "=> arg=$arg, split_arg=$split_arg, addtocache=$addtocache"
done
