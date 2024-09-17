# $NetBSD: opt-warnings-as-errors.mk,v 1.2 2024/09/17 11:52:32 jperkin Exp $
#
# Tests for the -W command line option, which turns warnings into errors.
#
# Even in -W mode, a .warning is not completely equivalent to an .error.
# First, the word "warning" is still printed, and second, parsing continues
# after a failed warning, whereas it would stop immediately at the first
# .error.

.MAKEFLAGS: -W

# expect+1: warning: message 1
.warning message 1
# expect+1: warning: message 2
.warning message 2

_!=	echo 'parsing continues' 1>&2

all:
	@:;
