# $NetBSD: suff-transform-debug.mk,v 1.1 2024/07/15 09:10:27 jperkin Exp $
#
# Test how the debug output of transformation rules looks.

.MAKEFLAGS: -dg1

.SUFFIXES: .a .c .cpp

.c.cpp .cpp.a:
	: Making ${.TARGET} from impsrc ${.IMPSRC} allsrc ${.ALLSRC}.

all:
