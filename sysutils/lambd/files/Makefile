#	$NetBSD: Makefile,v 1.2 2001/07/18 06:47:37 itojun Exp $

PROG=	lambd
SRCS=	lambd.c lambio.c
MAN=	lambd.8

WARNS?=	2
BINDIR?=	/sbin
LDSTATIC=	-static

LDADD+=	-li386
DPADD+=	/usr/lib/libi386.a

.include <bsd.prog.mk>
