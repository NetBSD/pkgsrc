# $NetBSD: Makefile,v 1.7 1998/06/18 16:15:10 agc Exp $
#

DISTNAME=       mpg123-0.59o
CATEGORIES=	audio
MASTER_SITES=   http://ftp.tu-clausthal.de/pub/unix/audio/mpg123/

MAINTAINER=	augustss@cs.chalmers.se

.if (${MACHINE_ARCH} == "i386")
ALL_TARGET=	netbsd-i386
.else
ALL_TARGET=	netbsd
.endif

MAKE_FLAGS+=	PREFIX="${PREFIX}"

.include "../../mk/bsd.pkg.mk"
