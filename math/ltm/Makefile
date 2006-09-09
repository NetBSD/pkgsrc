# $NetBSD: Makefile,v 1.7 2006/09/09 02:43:10 obache Exp $
#

DISTNAME=		ltm-0.30
PKGREVISION=		1
CATEGORIES=		math
MASTER_SITES=		http://math.libtomcrypt.org/files/
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://math.libtomcrypt.org/
COMMENT=		Number theoretic multiple-precision integer library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/libtommath-0.30
MAKE_FILE=		makefile
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
