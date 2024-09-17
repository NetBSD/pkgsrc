# $NetBSD: opt-debug-curdir.mk,v 1.2 2024/09/17 11:52:32 jperkin Exp $
#
# Tests for the -dC command line option, which does nothing, as of 2020-09-05,
# as the string "DEBUG(CWD" does not occur in the source code.

.MAKEFLAGS: -dC

all: .PHONY
