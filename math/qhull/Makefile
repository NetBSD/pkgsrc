# $NetBSD: Makefile,v 1.11 2023/09/06 13:22:43 nros Exp $

DISTNAME=	qhull-2020-src-${LIBVERSION}
PKGNAME=	qhull-2020.2
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://www.qhull.org/download/
EXTRACT_SUFX=	.tgz

LIBVERSION=	${LIBMAJOR}.2
LIBMAJOR=	8.0
PLIST_SUBST+=	LIBVERSION=${LIBVERSION} LIBMAJOR=${LIBMAJOR}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.qhull.org/
COMMENT=	Computing the convex hull

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
TEST_ENV+=	LD_LIBRARY_PATH=${WRKSRC}
TEST_TARGET=	test

CMAKE_ARGS+=	-DMAN_INSTALL_DIR:PATH=${PREFIX}/${PKGMANDIR}/man1

PKGCONFIG_OVERRIDE=	build/qhull.pc.in

# Remove non-portable file not used in build or test.
post-extract:
	rm -f ${WRKSRC}/eg/q_benchmark ${WRKSRC}/eg/qhull-zip.sh

# libqhull is deprecated
post-build:
	cd ${WRKSRC} && make libqhull

.include "../../mk/bsd.pkg.mk"
