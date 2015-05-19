# $NetBSD: order.mk,v 1.2 2015/05/19 22:01:19 joerg Exp $

# Test that .ORDER is handled correctly.
# The explicit dependency the.o: the.h will make us examine the.h
# the .ORDER will prevent us building it immediately,
# we should then examine the.c rather than stop.

all: the.o

.ORDER: the.c the.h

the.c the.h:
	@echo Making $@

.SUFFIXES: .o .c

.c.o:
	@echo Making $@ from $?

the.o: the.h
