# $NetBSD: Makefile,v 1.19 2016/10/04 09:29:46 wiz Exp $

DISTNAME=		ltm-1.0
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_GITHUB:=libtom/}
GITHUB_PROJECT=		libtommath
GITHUB_RELEASE=		v${PKGVERSION_NOREV}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://libtom.net/
COMMENT=		Number theoretic multiple-precision integer library
LICENSE=		public-domain

WRKSRC=			${WRKDIR}/libtommath-1.0
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
