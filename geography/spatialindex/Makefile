# $NetBSD: Makefile,v 1.6 2026/09/06 17:53:14 gdt Exp $

# Do not update to >= 2.1, because of an upstream bug that causes
# incorrect results in qgis (and arguably, any other user of the
# library).
#   https://github.com/libspatialindex/libspatialindex/issues/276
#   https://lists.osgeo.org/pipermail/qgis-developer/2025-September/067804.html
#   https://lists.osgeo.org/pipermail/qgis-developer/2025-September/067804.html
DISTNAME=	spatialindex-src-2.0.0
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=libspatialindex/}
GITHUB_PROJECT=	libspatialindex
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://libspatialindex.github.io/
COMMENT=	Robust spatial indexing methods
LICENSE=	mit

USE_LANGUAGES=		c c++
USE_CXX_FEATURES+=	c++11

# Remediate upstream spelling /bin/sh as /bin/bash.
# https://github.com/libspatialindex/libspatialindex/issues/299
SUBST_CLASSES+=		bash
SUBST_STAGE.bash=	pre-test
SUBST_FILES.bash=	test/*.sh test/*/*/run
SUBST_SED.bash=		-e 's,/bin/bash,/bin/sh,g'

# Testing is not documented and googletest is not described.
# So far, testing does not seem useful, so left off.
# https://github.com/libspatialindex/libspatialindex/issues/298
# https://github.com/libspatialindex/libspatialindex/issues/300
#TEST_TARGET=	test
#TEST_DEPENDS+=		googletest-[0-9]*:../../devel/googletest
#.include "../../devel/googletest/buildlink3.mk"
#USE_CXX_FEATURES+=	c++17

.include "../../devel/cmake/build.mk"

.include "../../mk/bsd.pkg.mk"
