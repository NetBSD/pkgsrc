# $NetBSD: Makefile,v 1.9 2006/09/09 09:35:10 obache Exp $
#

DISTNAME=		ltm-0.39
CATEGORIES=		math
MASTER_SITES=		http://math.libtomcrypt.com/files/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://math.libtomcrypt.com/
COMMENT=		Number theoretic multiple-precision integer library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/libtommath-0.39
MAKE_FILE=		makefile
BUILD_TARGET=		default
USE_TOOLS+=		gmake

INSTALLATION_DIRS=	share/doc/ltm

do-install:
	${INSTALL_DATA} ${WRKSRC}/tommath.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/tommath_class.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/tommath_superclass.h ${PREFIX}/include
	${INSTALL_LIB} ${WRKSRC}/libtommath.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/bn.pdf ${PREFIX}/share/doc/ltm
	${INSTALL_DATA} ${WRKSRC}/poster.pdf ${PREFIX}/share/doc/ltm
	${INSTALL_DATA} ${WRKSRC}/tommath.pdf ${PREFIX}/share/doc/ltm

.include "../../mk/bsd.pkg.mk"
