#	$NetBSD: Makefile,v 1.3 2007/12/31 03:09:31 obache Exp $

PROG=	lambd
SRCS=	lambd.c lambio.c
MAN=	lambd.8

WARNS?=	2
BINDIR=	${PREFIX}/sbin
LDSTATIC=	-static

LDADD+=	-li386
DPADD+=	/usr/lib/libi386.a

.include <bsd.prog.mk>
