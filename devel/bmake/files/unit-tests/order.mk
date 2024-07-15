# $NetBSD: order.mk,v 1.4 2024/07/15 09:10:25 jperkin Exp $

# Test that .ORDER is handled correctly.
# The explicit dependency the.o: the.h will make us examine the.h
# the .ORDER will prevent us building it immediately,
# we should then examine the.c rather than stop.

.MAKEFLAGS: -j1

all: the.o

.ORDER: the.c the.h

the.c the.h:
	@echo Making $@

.SUFFIXES: .o .c

.c.o:
	@echo Making $@ from $?

the.o: the.h
