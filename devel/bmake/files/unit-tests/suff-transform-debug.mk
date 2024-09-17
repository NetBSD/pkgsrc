# $NetBSD: suff-transform-debug.mk,v 1.2 2024/09/17 11:52:33 jperkin Exp $
#
# Test how the debug output of transformation rules looks.

.MAKEFLAGS: -dg1

.SUFFIXES: .a .c .cpp

.c.cpp .cpp.a:
	: Making ${.TARGET} from impsrc ${.IMPSRC} allsrc ${.ALLSRC}.

all:
