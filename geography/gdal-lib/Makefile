# $NetBSD: Makefile,v 1.164 2024/05/21 13:36:10 gdt Exp $

PKGREVISION= 11
.include "../../geography/gdal-lib/Makefile.common"
PKGNAME=	${DISTNAME:S/gdal/gdal-lib/}
#PKGREVISION=	0

COMMENT=	Translator library for raster geospatial data formats

USE_LANGUAGES+=		c c++
USE_C_FEATURES+=	c99
USE_CXX_FEATURES+=	c++11

# This package intends to link against only libgeos_c, but ends up
# also linking to the C++ library libgeos, apparently because of a
# libtool problem.
# Therefore this package needs revbumping on every geos update.

.include "../../devel/cmake/build.mk"
CMAKE_ARGS+=		-DBUILD_PYTHON_BINDINGS=OFF

.include "options.mk"

CHECK_PORTABILITY_SKIP+=	mkbindist.sh

INSTALLATION_DIRS=	bin include lib ${PKGMANDIR}/man1 share/gdal

# \todo: Support geopdf by including poppler, PoDoFo, or PDFium.
# https://gdal.org/drivers/raster/pdf.html

# As an exception to the "cmake change only" rule, enable spatialite because
# that's easier than working around a bug that causes cmake to fail because
# of an empty variable leading to a wrong number of args error.
#
# NB: spatialite requires sqlite3, so there is the spectre of base/pkg confusion.
# Therefore, include it first in the baseless hope that helps.
.include "../../geography/libspatialite/buildlink3.mk"

# \todo Enable zstd
# .include "../../archivers/zstd/buildlink3.mk"

# Avoid NetBSD base sqlite3, which is deficient because it lacks rtree.
# \todo Enhance pkgsrc to be able to declare that modules are needed.
#BUILDLINK_API_DEPENDS.sqlite3+= sqlite3>=3.36.0
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/netcdf/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../geography/geos/buildlink3.mk"
.include "../../geography/proj/buildlink3.mk"
.include "../../geography/libgeotiff/buildlink3.mk"
.include "../../math/qhull/buildlink3.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/openjpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
# \todo See USE_JSONC_INTERNAL in Makefile.common.
# .include "../../textproc/json-c/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/xerces-c/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
