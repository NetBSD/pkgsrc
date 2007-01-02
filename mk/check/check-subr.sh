# $NetBSD: check-subr.sh,v 1.5 2007/01/02 17:58:11 rillig Exp $
#
# This file contains shell functions that are used by the various shell
# programs that check things in pkgsrc. All these programs must be
# called with the following environment variables set:
#
# SKIP_FILTER
#	A shell expression of the form
#
#		*/pattern.*) continue;; *.txt) continue;;
#
#	that can be passed to eval(1) in order to skip the files
#	that are chosen by the respective *_SKIP variable in
#	make(1).
#

# Implementation notes:
#
# 1. The SKIP_FILTER variable should only be used in the following
# pattern, usually inside a "for" or "while" loop.
#
#	skip=no
#	eval "case \"\$fname\" in $SKIP_FILTER *.orig) skip=yes;; esac"
#	[ $skip = no ] || continue
#
# 2. The programs using this file are run with the tools wrapper
# directory in the PATH, so they call the utilities by their base names.
# They may also assume to be interpreted by a POSIX-conforming shell, in
# particular _not_ by the Solaris /bin/sh.
#

# All programs that check something are very strict.
set -eu

cs_exitcode=0

# usage: cs_setprogname "progname"
#
# This function sets the variable that will later be used in diagnostic
# messages to identify the program that generated the message.
cs_setprogname() {
	cs_progname="${1##*/}"
}

# Each diagnostic message can be preceded by a heading to better identify
# messages that belong together. The heading will only be printed if it
# differs from the last one.
cs_last_heading=""

# usage: cs_error_heading "new heading"
cs_error_heading() {
	if [ x"$1" != x"$cs_last_heading" ]; then
		cs_last_heading="$1"
		cs_error_msg "=> $1"
	fi
}

# usage: cs_warning_heading "new heading"
cs_warning_heading() {
	if [ x"$1" != x"$cs_last_heading" ]; then
		cs_last_heading="$1"
		cs_warning_msg "=> $1"
	fi
}

# usage: cs_error_msg "error message"
cs_error_msg() {
	echo "ERROR: [$cs_progname] $*" 1>&2
	cs_exitcode=1
}

# usage: cs_warning_msg "warning message"
cs_warning_msg() {
	echo "WARNING: [$cs_progname] $*" 1>&2
}

cs_hline=\
"==========================================================================="

# usage: cs_explain <<EOF
cs_explain() {
	{ echo ""
	  echo "Explanation:"
	  echo "$cs_hline"
	  cat
	  echo "$cs_hline"
	  echo ""
	} 1>&2
}

# usage: cs_exit
#
# At the end of the program, cs_exit should be called to return the
# appropriate exit status to the calling process. It is non-zero when
# any error messages have been printed and zero otherwise.
cs_exit() {
	exit "$cs_exitcode"
}
