# $NetBSD: suff-transform-expand.mk,v 1.2 2024/09/17 11:52:33 jperkin Exp $
#
# https://gnats.netbsd.org/49086, issue 11:
# Sources from transformation rules are expanded incorrectly.
#
# issue11.j should depend on issue11.i and issue11.second.
# issue11.i should depend on issue11.h and issue11.first.
#
# XXX: The dynamic sources are expanded before ${.PREFIX} and
# ${.TARGET} were available, so they expand to an empty string.

all: issue11.j

.SUFFIXES: .h .i .j

.h.i: ${.PREFIX}.first
	: 'Making ${.TARGET} from ${.IMPSRC} all ${.ALLSRC}.'

.i.j: ${.PREFIX}.second
	: 'Making ${.TARGET} from ${.IMPSRC} all ${.ALLSRC}.'

issue11.h issue11.first issue11.second:
	: 'Making ${.TARGET} out of nothing.'

#.MAKEFLAGS: -dg1
