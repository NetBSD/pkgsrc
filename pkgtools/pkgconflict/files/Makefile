# $NetBSD: Makefile,v 1.2 2002/04/08 16:26:15 wennmach Exp $

PGINCLUDE=@PREFIX@/include/pgsql

.c.o:
	cc -I${PGINCLUDE} -I${PGINCLUDE}/server -Wall -fpic -c $<

all: dewey_cmp.so

dewey_cmp.so: dewey_cmp.o
	cc -shared -o dewey_cmp.so dewey_cmp.o
