# $NetBSD: dep-percent.mk,v 1.2 2024/09/17 11:52:30 jperkin Exp $
#
# Test for transformation rules of the form '%.o: %.c', which are supported
# by GNU make but not this make.

.SUFFIXES: .c .o

all: dep-percent.o

%.o: %.c
	: 'Making ${.TARGET} from ${.IMPSRC} or ${.ALLSRC}.'

dep-percent.c:
	: 'Making ${.TARGET} out of nothing.'
