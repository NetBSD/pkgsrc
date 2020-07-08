# $NetBSD: Makefile,v 1.1 2020/07/08 14:25:38 nia Exp $

CFLAGS+=	-fPIC -Wall
LDFLAGS+=	-shared

all: utf8.so table.so string.so

.c.o:
	$(CC) $(CFLAGS) -c $<

utf8.so: lutf8lib.o
	$(CC) $(LDFLAGS) -o $@ lutf8lib.o

table.so: ltablib.o
	$(CC) $(LDFLAGS) -o $@ ltablib.o

string.so: lstrlib.o
	$(CC) $(LDFLAGS) -o $@ lstrlib.o
