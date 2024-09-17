# $NetBSD: jobs-error-nested.mk,v 1.2 2024/09/17 11:52:32 jperkin Exp $
#
# Ensure that in jobs mode, when a command fails, the current directory is
# printed, to aid in debugging.
#
# XXX: This test is run without the -k flag, which prints "stopped in" 4
# times.  Why?
#
# This particular case is not the cause for the PRs, but it is very close.
#
# https://gnats.netbsd.org/55578
# https://gnats.netbsd.org/55832

.MAKEFLAGS: -j1

all: .PHONY
	${MAKE} -f ${MAKEFILE} nested

nested: .PHONY
	false
