# $NetBSD: Makefile,v 1.208 2026/09/02 19:02:26 wiz Exp $

PKGREVISION= 1
.include "../../geography/gdal-lib/Makefile.common"
PKGNAME=	${DISTNAME:S/gdal/gdal-lib/}
#PKGREVISION=	0

COMMENT=	Translator library for raster geospatial data formats

USE_LANGUAGES+=		c c++
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
.PHONY: cmake-options
cmake-options:
	(cd ${WRKSRC}/cmake-pkgsrc-build && cmake -L ..) > OPTIONS

.include "../../devel/cmake/build.mk"

# Disable things that cmake finds that we didn't bl3.
# \todo For each, consider if we should intead add a bl3.
CMAKE_CONFIGURE_ARGS+=	-DGDAL_USE_ARROW=OFF
CMAKE_CONFIGURE_ARGS+=	-DGDAL_USE_CFITSIO=OFF
CMAKE_CONFIGURE_ARGS+=	-DGDAL_USE_DEFLATE=OFF
CMAKE_CONFIGURE_ARGS+=	-DGDAL_USE_FREEXL=OFF
CMAKE_CONFIGURE_ARGS+=	-DGDAL_USE_HDF5=OFF
CMAKE_CONFIGURE_ARGS+=	-DGDAL_USE_HEIF=OFF
CMAKE_CONFIGURE_ARGS+=	-DGDAL_USE_LZ4=OFF
CMAKE_CONFIGURE_ARGS+=	-DGDAL_USE_ODBC=OFF
CMAKE_CONFIGURE_ARGS+=	-DGDAL_USE_OPENEXR=OFF
CMAKE_CONFIGURE_ARGS+=	-DGDAL_USE_PARQUET=OFF

# Disable python bindings because it is in ../py-gdal.  The reasons
# are to allow multiple python versions, and to remove the dependency
# on numpy and hence the need for blas and fortran from the base gdal
# package.
CMAKE_CONFIGURE_ARGS+=		-DBUILD_PYTHON_BINDINGS=OFF

# Disable things that we don't want to build, more as documentation
# than them needing to be forced off.
CMAKE_CONFIGURE_ARGS+=		-DBUILD_CSHARP_BINDINGS=OFF
CMAKE_CONFIGURE_ARGS+=		-DBUILD_JAVA_BINDINGS=OFF

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

SUBST_CLASSES+=		rpath
SUBST_SED.rpath+=	-E
SUBST_SED.rpath+=	-e 's!(CONFIG_LIBS=.)!\1${COMPILER_RPATH_FLAG}${PREFIX}/lib !'
SUBST_SED.rpath+=	-e 's!(CONFIG_DEP_LIBS=.)!\1${COMPILER_RPATH_FLAG}${PREFIX}/lib !'
SUBST_STAGE.rpath=	pre-configure
SUBST_FILES.rpath+=	cmake/template/gdal-config.in
SUBST_MESSAGE.rpath=	Fixing rpath in config script.

.include "options.mk"

CHECK_PORTABILITY_SKIP+=	mkbindist.sh

INSTALLATION_DIRS=	bin include lib ${PKGMANDIR}/man1 share/gdal

PLIST_VARS+=	le

.include "../../mk/endian.mk"

PLIST_SUBST+=		VERSION=${VERSION_BASE}
PRINT_PLIST_AWK+=	{ gsub(/${VERSION_BASE}/, "$${VERSION}") }

# In ogr/ogrsf_frmts/CMakeLists.txt, the building of the miramon
# sub-system is dependent on "NOT WORDS_BIGENDIAN".
PRINT_PLIST_AWK+=	/MM_m_idofic.csv/ { print "$${PLIST.le}" $$0; next }

.if ${MACHINE_ENDIAN} != "big"
PLIST.le=	yes
.endif

# GeoPDF support: https://gdal.org/drivers/raster/pdf.html
# \todo: Decide about reading geopdf.  gdal can use, in order of
# preference, PDFium, poppler with the unstable API enabled, and
# PoDoFo (with pdftoppm).  PoDoFo is described as a partial
# alternative.
#
# pkg_info -S increase:
#   poppler: 18.4 MB
#   PoDoFo: 6.8 MB
# but I don't believe that because the PoDoFo build depends on poppler
# and is less by poppler-includes (1.5MB) and greater by PoDoFo and
# any deps it has that aren't required by poppler or gdal-lib.
#
# PDFium is not in pkgsrc.  Choose poppler as not that heavy and
# satisfactory.
# \todo Consider moving poppler to a default-on option if there are
# complaints.
CMAKE_CONFIGURE_ARGS+=	-DGDAL_USE_PDFIUM=OFF
#CMAKE_CONFIGURE_ARGS+=	-DGDAL_USE_POPPLER=OFF
CMAKE_CONFIGURE_ARGS+=	-DGDAL_USE_PODOFO=OFF
.include "../../print/poppler/buildlink3.mk"
.include "../../print/poppler-includes/buildlink3.mk"
#.include "../../print/podofo/buildlink3.mk"
#DEPENDS+=	poppler-utils-[0-9]*:../../print/poppler-utils


.include "../../mk/atomic64.mk"

.include "../../archivers/libarchive/buildlink3.mk"
# Confusingly, liblzma is part of xz.
.include "../../archivers/xz/buildlink3.mk"
.include "../../archivers/zstd/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/netcdf/buildlink3.mk"
.include "../../devel/pcre2/buildlink3.mk"
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
.include "../../textproc/json-c/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/xerces-c/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
