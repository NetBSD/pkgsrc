#	$NetBSD: Makefile,v 1.1 2013/08/28 11:42:36 jperkin Exp $
#	NetBSD: Makefile,v 1.21 2006/12/16 12:59:17 bouyer Exp 
#	@(#)Makefile	8.1 (Berkeley) 6/6/93

.include <bsd.own.mk>

PROG=	bsdinstall
SRCS=	bsdinstall.c setmode.c
MAN=	bsdinstall.1

LDADD+= -lnbcompat

COPTS.xinstall.c += -Wno-format-nonliteral

.include <bsd.prog.mk>
