# $NetBSD: opt-silent.mk,v 1.2 2024/09/17 11:52:32 jperkin Exp $
#
# Tests for the -s command line option.

.MAKEFLAGS: -s

# No matter whether a command is prefixed by '@' or not, it is not echoed.
all:
	echo 'message'
	@echo 'silent message'
