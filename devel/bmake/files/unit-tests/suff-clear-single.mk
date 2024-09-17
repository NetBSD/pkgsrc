# $NetBSD: suff-clear-single.mk,v 1.2 2024/09/17 11:52:33 jperkin Exp $
#
# https://gnats.netbsd.org/49086, issue 3:
# Single suffix rules remain active after .SUFFIXES is cleared.
#
# There's a rule for issue3.a, but .a is no longer a known suffix when
# targets are being made, so issue3 should not get made.

all: issue3

.SUFFIXES: .a .b .c

.a .a.b .b.a:
	: 'Making ${.TARGET} from ${.IMPSRC}.'

.SUFFIXES:

issue3.a:
	: 'There is a bug if you see this.'
