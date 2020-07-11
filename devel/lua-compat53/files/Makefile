# $NetBSD: Makefile,v 1.2 2020/07/11 13:48:49 nia Exp $

CFLAGS+=	-fPIC -Wall
LDFLAGS+=	-shared

all: utf8.so table.so string.so tests/testmod.so

.c.o:
	$(CC) $(CFLAGS) -c $<

testmod.o: tests/testmod.c
	$(CC) $(CFLAGS) -Ic-api/ -c $<

utf8.so: lutf8lib.o
	$(CC) $(LDFLAGS) -o $@ lutf8lib.o

table.so: ltablib.o
	$(CC) $(LDFLAGS) -o $@ ltablib.o

string.so: lstrlib.o
	$(CC) $(LDFLAGS) -o $@ lstrlib.o

tests/testmod.so: testmod.o
	$(CC) $(LDFLAGS) -o $@ testmod.o
