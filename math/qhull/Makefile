# $NetBSD: Makefile,v 1.13 2024/08/25 06:19:01 wiz Exp $

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

# libqhull is deprecated
post-build:
	cd ${WRKSRC}/${CMAKE_BUILD_DIR} && make libqhull

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
