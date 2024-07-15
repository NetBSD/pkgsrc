# $NetBSD: opt-silent.mk,v 1.1 2024/07/15 09:10:24 jperkin Exp $
#
# Tests for the -s command line option.

.MAKEFLAGS: -s

# No matter whether a command is prefixed by '@' or not, it is not echoed.
all:
	echo 'message'
	@echo 'silent message'
