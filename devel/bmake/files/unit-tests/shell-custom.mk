# $NetBSD: shell-custom.mk,v 1.2 2024/09/17 11:52:33 jperkin Exp $
#
# Tests for using a custom shell for running the commands.

.SHELL: name="sh" path="echo"
# TODO: demonstrate the other shell features as well:
# - error control
# - output control

all:
	: normal
	@: hidden
	+: always
	-: ignore errors
