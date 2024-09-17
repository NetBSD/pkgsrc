# $NetBSD: shell-sh.mk,v 1.2 2024/09/17 11:52:33 jperkin Exp $
#
# Tests for using a bourne shell for running the commands.
# This is the default shell, so there's nothing surprising.

.SHELL: name="sh"

all:
	: normal
	@: hidden
	+: always
	-: ignore errors
