# $NetBSD: Makefile,v 1.1.1.1 1999/05/22 20:57:43 tv Exp $

all: sq usq

sq: sq.o tr1.o tr2.o sqio.o
	${LINK.c} -o $@ $>

usq: usq.o utr.o
	${LINK.c} -o $@ $>
