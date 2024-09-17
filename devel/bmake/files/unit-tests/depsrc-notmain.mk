# $NetBSD: depsrc-notmain.mk,v 1.2 2024/09/17 11:52:30 jperkin Exp $
#
# Tests for the special source .NOTMAIN in dependency declarations,
# which prevents the associated target from becoming the default target
# to be made.

ignored: .NOTMAIN
	: ${.TARGET}

all:
	: ${.TARGET}
