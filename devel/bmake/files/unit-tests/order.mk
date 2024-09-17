# $NetBSD: order.mk,v 1.5 2024/09/17 11:52:33 jperkin Exp $

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
