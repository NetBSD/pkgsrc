# $NetBSD: Makefile,v 1.5 2003/11/07 13:04:00 gavan Exp $

DISTNAME=	mjpegtools-1.6.0
PKGNAME=	mplex-1.6.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mjpeg/}

MAINTAINER=	collver1@comcast.net
HOMEPAGE=	http://mjpeg.sourceforge.net
COMMENT=	Multiplexes MPEG component streams into system layers

BUILD_DEPENDS+=	nasm>=0.98:../../devel/nasm

USE_GMAKE=	yes
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
USE_GCC_SHLIB=	yes

do-build:
	cd ${WRKSRC}/utils && ${GMAKE}
	cd ${WRKSRC}/mplex && ${GMAKE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mplex/mplex ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mplex
	for FILE in COPYING INSTRUCT README; do \
	  ${INSTALL_DATA} ${WRKSRC}/mplex/$$FILE ${PREFIX}/share/doc/mplex; \
	done

.include "../../mk/bsd.pkg.mk"
