#	$NetBSD: Makefile,v 1.2 2020/03/29 00:58:31 joerg Exp $

PROG=   crunchide
SRCS=	crunchide.c
#MAN=	crunchide.1
MKMAN=	no
MKPIE=	no

BINDIR=	${PREFIX}/bin

COPTS+= ${CPPFLAGS}
LDADD+= ${LIBS}

.include <bsd.prog.mk>
