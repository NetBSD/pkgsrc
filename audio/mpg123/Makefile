# New ports collection makefile for:	mpg123
# Version required:     mpg123-0.59k
# Date created:		97-10-25
# Whom:			augustss@cs.chalmers.se
#
# $NetBSD: Makefile,v 1.5 1998/03/07 13:55:38 mycroft Exp $
#

DISTNAME=       mpg123-0.59o
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
