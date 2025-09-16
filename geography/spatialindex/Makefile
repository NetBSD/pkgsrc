# $NetBSD: Makefile,v 1.3 2025/09/16 00:43:35 gdt Exp $

# Do not update to >= 2.1, because of an upstream bug that causes
# incorrect results in qgis (and arguably, any other user of the
# library).
#   https://github.com/libspatialindex/libspatialindex/commit/6fe9ff769243579ed74f7f27409dd1dda6591634
#   https://lists.osgeo.org/pipermail/qgis-developer/2025-September/067804.html
#   https://lists.osgeo.org/pipermail/qgis-developer/2025-September/067804.html
DISTNAME=	spatialindex-src-1.9.3
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

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
