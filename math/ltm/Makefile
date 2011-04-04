# $NetBSD: Makefile,v 1.15 2011/04/04 10:48:32 drochner Exp $
#

DISTNAME=		ltm-0.42.0
PKGREVISION=		1
CATEGORIES=		math
MASTER_SITES=		http://libtom.org/files/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://libtom.org/
COMMENT=		Number theoretic multiple-precision integer library
LICENSE=		public-domain

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/libtommath-0.42.0
USE_LIBTOOL=		yes
MAKE_FILE=		makefile.shared
BUILD_TARGET=		default
USE_TOOLS+=		gmake

AUTO_MKDIRS=		yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/tommath.h ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/tommath_class.h ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/tommath_superclass.h ${DESTDIR}${PREFIX}/include
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/libtommath.la \
		${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/bn.pdf ${DESTDIR}${PREFIX}/share/doc/ltm
	${INSTALL_DATA} ${WRKSRC}/poster.pdf ${DESTDIR}${PREFIX}/share/doc/ltm
	${INSTALL_DATA} ${WRKSRC}/tommath.pdf ${DESTDIR}${PREFIX}/share/doc/ltm

.include "../../mk/bsd.pkg.mk"
