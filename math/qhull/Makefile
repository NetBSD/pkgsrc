# $NetBSD: Makefile,v 1.14 2025/01/16 23:04:22 wiz Exp $

DISTNAME=	qhull-2020-src-${LIBVERSION}
PKGNAME=	qhull-2020.2
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://www.qhull.org/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.qhull.org/
COMMENT=	Computing the convex hull

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

USE_LANGUAGES=	c c++
TEST_ENV+=	LD_LIBRARY_PATH=${WRKSRC}
TEST_TARGET=	test

LIBVERSION=	${LIBMAJOR}.2
LIBMAJOR=	8.0
PLIST_SUBST+=	LIBVERSION=${LIBVERSION} LIBMAJOR=${LIBMAJOR}

CMAKE_CONFIGURE_ARGS+=	-DMAN_INSTALL_DIR:PATH=${PREFIX}/${PKGMANDIR}/man1

PKGCONFIG_OVERRIDE=	build/qhull.pc.in

# Remove non-portable file not used in build or test.
post-extract:
	rm -f ${WRKSRC}/eg/q_benchmark ${WRKSRC}/eg/qhull-zip.sh

.include "../../devel/cmake/build.mk"

# libqhull is deprecated
post-build:
.if ${CMAKE_GENERATOR} == "make"
	cd ${WRKSRC}/${CMAKE_BUILD_DIR} && make libqhull
.else
	cd ${WRKSRC}/${CMAKE_BUILD_DIR} && ninja libqhull
.endif

.include "../../mk/bsd.pkg.mk"
