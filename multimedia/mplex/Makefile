# $NetBSD: Makefile,v 1.4 2004/03/30 19:51:31 ben Exp $

DISTNAME=	mjpegtools-1.6.2
PKGNAME=	mplex-1.6.2
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mjpeg/}

MAINTAINER=	ben@NetBSD.org
HOMEPAGE=	http://mjpeg.sourceforge.net/
COMMENT=	Multiplexes MPEG component streams into system layers

BUILD_DEPENDS+=	nasm>=0.98:../../devel/nasm

USE_GNU_TOOLS+=	make
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
USE_GCC_SHLIB=	yes
USE_BUILDLINK3=	yes

do-build:
	cd ${WRKSRC}/utils && ${GMAKE}
	cd ${WRKSRC}/mplex && ${GMAKE}

do-install:
	cd ${WRKSRC}/mplex && \
		${LIBTOOL} --mode=install ${INSTALL_DATA} libmplex2.la \
			${PREFIX}/lib && \
		${LIBTOOL} --mode=install ${INSTALL_PROGRAM} mplex ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mplex
	for FILE in COPYING INSTRUCT README; do \
	  ${INSTALL_DATA} ${WRKSRC}/mplex/$$FILE ${PREFIX}/share/doc/mplex; \
	done

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
