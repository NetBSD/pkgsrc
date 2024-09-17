# $NetBSD: opt-where-am-i.mk,v 1.2 2024/09/17 11:52:33 jperkin Exp $
#
# Tests for the -w command line option, which outputs the current directory
# at the beginning and end of running make.  This is useful when building
# large source trees that involve several nested make calls.

# The first "Entering directory" is missing since the below .MAKEFLAGS comes
# too late for it.
.MAKEFLAGS: -w

all:
.if ${.CURDIR} != "/"
	@MAKE_OBJDIR_CHECK_WRITABLE=no ${MAKE} -r -f ${MAKEFILE:tA} -C /
.endif
