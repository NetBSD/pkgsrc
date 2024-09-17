# $NetBSD: shell-ksh.mk,v 1.2 2024/09/17 11:52:33 jperkin Exp $
#
# Tests for using a korn shell for running the commands.

.SHELL: name="ksh" path="ksh"

all:
	: normal
	@: hidden
	+: always
	-: ignore errors
