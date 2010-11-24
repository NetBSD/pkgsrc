# $NetBSD: Makefile,v 1.13 2010/11/24 01:09:48 agc Exp $
#

DISTNAME=		ltm-0.42.0
CATEGORIES=		math
MASTER_SITES=		http://libtom.org/files/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://math.libtomcrypt.com/
COMMENT=		Number theoretic multiple-precision integer library
LICENSE=		public-domain

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/libtommath-0.42.0
MAKE_FILE=		makefile
BUILD_TARGET=		default
USE_TOOLS+=		gmake

AUTO_MKDIRS=		yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/tommath.h ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/tommath_class.h ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/tommath_superclass.h ${DESTDIR}${PREFIX}/include
	${INSTALL_LIB} ${WRKSRC}/libtommath.a ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/bn.pdf ${DESTDIR}${PREFIX}/share/doc/ltm
	${INSTALL_DATA} ${WRKSRC}/poster.pdf ${DESTDIR}${PREFIX}/share/doc/ltm
	${INSTALL_DATA} ${WRKSRC}/tommath.pdf ${DESTDIR}${PREFIX}/share/doc/ltm

.include "../../mk/bsd.pkg.mk"
