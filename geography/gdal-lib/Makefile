# $NetBSD: Makefile,v 1.103 2018/08/16 18:54:29 adam Exp $

PKGREVISION= 4
.include "../../geography/gdal-lib/Makefile.common"
PKGNAME=	${DISTNAME:S/gdal/gdal-lib/}

MAINTAINER=	brook@nmsu.edu
#MAINTAINER+=	gdt@NetBSD.org
HOMEPAGE=	http://www.gdal.org/
COMMENT=	Translator library for raster geospatial data formats
LICENSE=	mit

# This package links against the geos C++ library.  geos regards this
# as a bug and changes the C++ shlib version every release.  Therefore
# this package needs revbumping on every geos update.

CONFIGURE_ARGS+=	--without-python

MAKE_FILE=		GNUmakefile

.include "options.mk"

CHECK_PORTABILITY_SKIP+=	mkbindist.sh

INSTALLATION_DIRS=	bin include lib ${PKGMANDIR}/man1 share/gdal

# jasper uses SIZE_MAX and friends in its headers.
CPPFLAGS+=	-D__STDC_LIMIT_MACROS

.include "../../devel/netcdf/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../geography/geos/buildlink3.mk"
.include "../../geography/proj/buildlink3.mk"
.include "../../graphics/jasper/buildlink3.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/openjpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/xerces-c/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
