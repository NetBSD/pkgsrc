# $NetBSD: depsrc-notmain.mk,v 1.1 2024/07/15 09:10:14 jperkin Exp $
#
# Tests for the special source .NOTMAIN in dependency declarations,
# which prevents the associated target from becoming the default target
# to be made.

ignored: .NOTMAIN
	: ${.TARGET}

all:
	: ${.TARGET}
