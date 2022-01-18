# $NetBSD: Makefile,v 1.145 2022/01/18 16:25:20 gdt Exp $

.include "../../geography/gdal-lib/Makefile.common"
PKGNAME=	${DISTNAME:S/gdal/gdal-lib/}
#PKGREVISION=	0

COMMENT=	Translator library for raster geospatial data formats

USE_LANGUAGES+=	c99 c++11

# This package intends to link against only libgeos_c, but ends up
# also linking to the C++ library libgeos, apparently because of a
# libtool problem.
# Therefore this package needs revbumping on every geos update.

CONFIGURE_ARGS+=	--without-python

CONFIGURE_ARGS+=	--with-proj
CONFIGURE_ARGS+=	--with-sqlite3=${BUILDLINK_PREFIX.sqlite3}

MAKE_FILE=		GNUmakefile

.include "options.mk"

CHECK_PORTABILITY_SKIP+=	mkbindist.sh

INSTALLATION_DIRS=	bin include lib ${PKGMANDIR}/man1 share/gdal

# jasper uses SIZE_MAX and friends in its headers.
CPPFLAGS+=	-D__STDC_LIMIT_MACROS

# \todo: Support geopdf by including poppler, PoDoFo, or PDFium.
# https://gdal.org/drivers/raster/pdf.html

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
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/xerces-c/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
