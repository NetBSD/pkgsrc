# $NetBSD: Makefile,v 1.1 2020/07/09 15:27:56 nia Exp $

CFLAGS+=	-fPIC -Wall
LDFLAGS+=	-shared

all: lsqlite3.so

.c.o:
	$(CC) $(CFLAGS) -c $<

lsqlite3.so: lsqlite3.o
	$(CC) $(LDFLAGS) -lsqlite3 -o $@ lsqlite3.o
