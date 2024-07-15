# $NetBSD: opt-debug-curdir.mk,v 1.1 2024/07/15 09:10:22 jperkin Exp $
#
# Tests for the -dC command line option, which does nothing, as of 2020-09-05,
# as the string "DEBUG(CWD" does not occur in the source code.

.MAKEFLAGS: -dC

all: .PHONY
