# $NetBSD: Makefile,v 1.3 2004/06/27 13:40:20 grant Exp $

PGINCLUDE=@PREFIX@/include/pgsql

.c.o:
	cc -I${PGINCLUDE} -I${PGINCLUDE}/server -fpic -c $<

all: dewey_cmp.so

dewey_cmp.so: dewey_cmp.o
	cc -shared -o dewey_cmp.so dewey_cmp.o
