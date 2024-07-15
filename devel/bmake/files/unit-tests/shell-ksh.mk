# $NetBSD: shell-ksh.mk,v 1.1 2024/07/15 09:10:26 jperkin Exp $
#
# Tests for using a korn shell for running the commands.

.SHELL: name="ksh" path="ksh"

all:
	: normal
	@: hidden
	+: always
	-: ignore errors
