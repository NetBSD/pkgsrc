# $NetBSD: Makefile,v 1.1.1.1 2001/04/02 18:04:04 wennmach Exp $

PGINCLUDE=@PREFIX@/include/pgsql

.c.o:
	cc -I${PGINCLUDE} -Wall -fpic -c $<

all: dewey_cmp.so

dewey_cmp.so: dewey_cmp.o
	cc -shared -o dewey_cmp.so dewey_cmp.o
