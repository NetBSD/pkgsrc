# $NetBSD: Makefile,v 1.22 2017/09/26 14:34:23 mspo Exp $

DISTNAME=		ltm-1.0.1
PKGREVISION=		1
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_GITHUB:=libtom/}
GITHUB_PROJECT=		libtommath
GITHUB_RELEASE=		v${PKGVERSION_NOREV}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://libtom.net/
COMMENT=		Number theoretic multiple-precision integer library
LICENSE=		public-domain

WRKSRC=			${WRKDIR}/libtommath-1.0.1
USE_LIBTOOL=		yes
MAKE_FILE=		makefile.shared
MAKE_ENV+=		LIBPATH=${PREFIX}/lib
BUILD_TARGET=		default
USE_TOOLS+=		gmake

INSTALLATION_DIRS=	include lib share/doc/ltm

do-install:
	${INSTALL_DATA} ${WRKSRC}/tommath.h ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/tommath_class.h ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/tommath_superclass.h ${DESTDIR}${PREFIX}/include
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/libtommath.la \
		${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/doc/bn.pdf ${DESTDIR}${PREFIX}/share/doc/ltm
	${INSTALL_DATA} ${WRKSRC}/doc/poster.pdf ${DESTDIR}${PREFIX}/share/doc/ltm
	${INSTALL_DATA} ${WRKSRC}/doc/tommath.pdf ${DESTDIR}${PREFIX}/share/doc/ltm

.include "../../mk/bsd.pkg.mk"
