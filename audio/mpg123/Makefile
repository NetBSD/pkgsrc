# $NetBSD: Makefile,v 1.2 1997/10/28 23:59:56 augustss Exp $
# New ports collection makefile for:	mpg123
# Version required:     mpg123-0.59k
# Date created:		97-10-25
# Whom:			augustss@cs.chalmers.se
#

DISTNAME=       mpg123-0.59k
CATEGORIES=	audio
MASTER_SITES=   http://ftp.tu-clausthal.de/pub/unix/audio/mpg123/

MAINTAINER=	augustss@cs.chalmers.se

MAN1=		mpg123.1

.if (${MACHINE_ARCH} == "i386")
ALL_TARGET=	netbsd-i386
.else
ALL_TARGET=	netbsd
.endif

MAKE_FLAGS+=	PREFIX="${PREFIX}"

.include <bsd.port.mk>
