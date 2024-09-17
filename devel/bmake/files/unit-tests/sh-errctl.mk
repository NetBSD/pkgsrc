# $NetBSD: sh-errctl.mk,v 1.2 2024/09/17 11:52:33 jperkin Exp $
#
# Test a shell with error control.  This only works in jobs mode; in compat
# mode, the default shell is always used, see InitShellNameAndPath.
#
# There is a subtle difference between error control and echo control.
# With error control, each simple command is checked, whereas with echo
# control, only the last command from each line is checked.  A shell command
# line that behaves differently in these two modes is "false; true".  In
# error control mode, this fails, while in echo control mode, it succeeds.

.MAKEFLAGS: -j1 -dj

.SHELL: \
	name="sh" \
	path="${.SHELL}" \
	hasErrCtl="yes" \
	check="\# error checking on\nset -e" \
	ignore="\# error checking off\nset +e" \
	echo="\# echo on" \
	quiet="\# echo off"

all:
	@echo silent
	-echo ignerr; false
	+echo always
