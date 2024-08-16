# $NetBSD: Makefile,v 1.176 2024/08/16 11:58:38 gdt Exp $

.include "../../geography/gdal-lib/Makefile.common"
PKGNAME=	${DISTNAME:S/gdal/gdal-lib/}
#PKGREVISION=	0

COMMENT=	Translator library for raster geospatial data formats

USE_LANGUAGES+=		c c++
USE_CC_FEATURES+=	c99
USE_CXX_FEATURES+=	c++17 charconv

USE_TOOLS+=		gmake
USE_TOOLS+=		pkg-config

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes

# This package intends to link against only libgeos_c, but ends up
# also linking to the C++ library libgeos, apparently because of a
# libtool problem.
# Therefore this package needs revbumping on every geos update.

# To find out what can be set in the cmake build.
# \todo Hoist to cmake/build.mk.
cmake-options:
	(cd ${WRKSRC}/cmake-pkgsrc-build && cmake -L ..) > OPTIONS

.include "../../devel/cmake/build.mk"

# \todo Justify or change to bl3 on json-c
CMAKE_CONFIGURE_ARGS+=	-DGDAL_USE_JSONC_INTERNAL=ON
CMAKE_CONFIGURE_ARGS+=	-DGDAL_USE_JSONC=OFF

# Disable things that cmake finds that we didn't bl3.
# \todo For each, consider if we should intead add a bl3.
CMAKE_CONFIGURE_ARGS+=	-DGDAL_USE_ARROW=OFF
CMAKE_CONFIGURE_ARGS+=	-DGDAL_USE_CFITSIO=OFF
CMAKE_CONFIGURE_ARGS+=	-DGDAL_USE_DEFLATE=OFF
CMAKE_CONFIGURE_ARGS+=	-DGDAL_USE_FREEXL=OFF
CMAKE_CONFIGURE_ARGS+=	-DGDAL_USE_HDF5=OFF
CMAKE_CONFIGURE_ARGS+=	-DGDAL_USE_HEIF=OFF
CMAKE_CONFIGURE_ARGS+=	-DGDAL_USE_LZ4=OFF
# \todo Resolve LZMA usage.
# GDAL_USE_LZMA appears in gtif but cmake says it doesn't exist.
#CMAKE_CONFIGURE_ARGS+=	-DGDAL_USE_LZMA=OFF
CMAKE_CONFIGURE_ARGS+=	-DGDAL_USE_ODBC=OFF
CMAKE_CONFIGURE_ARGS+=	-DGDAL_USE_OPENEXR=OFF
CMAKE_CONFIGURE_ARGS+=	-DGDAL_USE_PARQUET=OFF
CMAKE_CONFIGURE_ARGS+=	-DGDAL_USE_PCRE2=OFF
CMAKE_CONFIGURE_ARGS+=	-DGDAL_USE_PODOFO=OFF
CMAKE_CONFIGURE_ARGS+=	-DGDAL_USE_POPPLER=OFF
CMAKE_CONFIGURE_ARGS+=	-DGDAL_USE_ZSTD=OFF

# Disable python bindings because it is in ../py-gdal.  The reasons
# are to allow multiple python versions, and to remove the dependency
# on numpy and hence the need for blas and fortran from the base gdal
# package.
CMAKE_ARGS+=		-DBUILD_PYTHON_BINDINGS=OFF

# Disable things that we don't want to build, more as documentation
# than them needing to be forced off.
CMAKE_ARGS+=		-DBUILD_CSHARP_BINDINGS=OFF
CMAKE_ARGS+=		-DBUILD_JAVA_BINDINGS=OFF

# \todo One would think these are unnnecessary.  Check if these
# can/should be dropped.  If not, explain why we have some and not
# all.  Commented lines are incompletely translated from autoconf,
# because there is no obvious analog.
CMAKE_CONFIGURE_ARGS+=	-DGEOS_DIR=${BUILDLINK_PREFIX.geos}
CMAKE_CONFIGURE_ARGS+=	-DTiff_DIR=${BUILDLINK_PREFIX.tiff}
#CMAKE_CONFIGURE_ARGS+=	-Dlibz=${BUILDLINK_PREFIX.zlib}
CMAKE_CONFIGURE_ARGS+=	-DNetCDF_DIR=${BUILDLINK_PREFIX.netcdf}
#CMAKE_CONFIGURE_ARGS+=	-Dwebp=${BUILDLINK_PREFIX.libwebp}
#CMAKE_CONFIGURE_ARGS+=	-Dxerces
#CMAKE_CONFIGURE_ARGS+=	-Dxerces-inc=${BUILDLINK_PREFIX.xerces-c}/include
#CMAKE_CONFIGURE_ARGS+=	-Dxerces-lib=-L${BUILDLINK_PREFIX.xerces-c}/lib\ -lxerces-c

.include "options.mk"

CHECK_PORTABILITY_SKIP+=	mkbindist.sh

INSTALLATION_DIRS=	bin include lib ${PKGMANDIR}/man1 share/gdal

# \todo: Support geopdf by including poppler, PoDoFo, or PDFium.
# https://gdal.org/drivers/raster/pdf.html

# \todo Enable zstd
# .include "../../archivers/zstd/buildlink3.mk"

.include "../../archivers/libarchive/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/netcdf/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../geography/geos/buildlink3.mk"
.include "../../geography/proj/buildlink3.mk"
.include "../../geography/libgeotiff/buildlink3.mk"
.include "../../geography/libspatialite/buildlink3.mk"
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
