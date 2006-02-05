# $NetBSD: Makefile,v 1.5 2006/02/05 23:10:02 joerg Exp $
#

DISTNAME=		ltm-0.30
PKGREVISION=		1
CATEGORIES=		math
MASTER_SITES=		http://math.libtomcrypt.org/files/
EXTRACT_SUFX=		.zip

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://math.libtomcrypt.org/
COMMENT=		Number theoretic multiple-precision integer library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/libtommath-0.30
MAKEFILE=		makefile
BUILD_TARGET=		default

INSTALLATION_DIRS=	include lib

do-install:
	${INSTALL_DATA} ${WRKSRC}/tommath.h ${PREFIX}/include
	${INSTALL_LIB} ${WRKSRC}/libtommath.a ${PREFIX}/lib
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ltm
	${INSTALL_DATA} ${WRKSRC}/bn.pdf ${PREFIX}/share/doc/ltm
	${INSTALL_DATA} ${WRKSRC}/poster.pdf ${PREFIX}/share/doc/ltm
	${INSTALL_DATA} ${WRKSRC}/tommath.pdf ${PREFIX}/share/doc/ltm

.include "../../mk/bsd.pkg.mk"
