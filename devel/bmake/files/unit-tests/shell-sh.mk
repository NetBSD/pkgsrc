# $NetBSD: shell-sh.mk,v 1.1 2024/07/15 09:10:26 jperkin Exp $
#
# Tests for using a bourne shell for running the commands.
# This is the default shell, so there's nothing surprising.

.SHELL: name="sh"

all:
	: normal
	@: hidden
	+: always
	-: ignore errors
