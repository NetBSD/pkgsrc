# $NetBSD: Makefile,v 1.9 1998/10/30 03:11:51 mycroft Exp $
#

DISTNAME=       mpg123-0.59o
CATEGORIES=	audio
MASTER_SITES=   http://ftp.tu-clausthal.de/pub/unix/audio/mpg123/

MAINTAINER=	augustss@cs.chalmers.se
HOMEPAGE=	http://mpg.123.org/

.if (${MACHINE_ARCH} == "i386")
ALL_TARGET=	netbsd-i386
.else
ALL_TARGET=	netbsd
.endif

MAKE_FLAGS+=	PREFIX="${PREFIX}"

post-patch:
	cp files/decode_i586_.s ${WRKSRC}/

.include "../../mk/bsd.pkg.mk"
