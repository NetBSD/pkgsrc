# $NetBSD: Makefile,v 1.42 2012/01/25 21:28:14 gdt Exp $

VERSION=	1.8.1
DISTNAME=	gdal-${VERSION}
PKGNAME=	gdal-lib-${VERSION}
CATEGORIES=	geography
MASTER_SITES=	http://download.osgeo.org/gdal/

MAINTAINER=	brook@nmsu.edu
HOMEPAGE=	http://www.gdal.org/
COMMENT=	Translator library for raster geospatial data formats
LICENSE=	mit

# There is mysterious failure to find gdal_version.h, even though it
# is not a generated file, apparently caused by an odd make path that
# fails to use the right includes.
MAKE_JOBS_SAFE=		no

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++ fortran77
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-geos
# This version of gdal requires the TIFF function TIFFUnsetField,
# which apparently is not part of the tiff v3.9.4 API.  That, however,
# is the most recent stable release of tiff.  Consequently, for the
# time being the internal tiff library will be used.
CONFIGURE_ARGS+=	--with-libtiff=internal
CONFIGURE_ARGS+=	--with-libz=${BUILDLINK_PREFIX.zlib}/include
CONFIGURE_ARGS+=	--with-xerces
CONFIGURE_ARGS+=	--with-xerces-inc=${BUILDLINK_PREFIX.xerces-c}/include
CONFIGURE_ARGS+=	--with-xerces-lib=-L${BUILDLINK_PREFIX.xerces-c}/lib\ -lxerces-c
CONFIGURE_ARGS+=	--without-python

MAKE_FILE=		GNUmakefile

.include "options.mk"

CHECK_PORTABILITY_SKIP+=	mkbindist.sh

INSTALLATION_DIRS=	bin include lib ${PKGMANDIR}/man1 share/gdal

.include "../../devel/zlib/buildlink3.mk"
.include "../../geography/geos/buildlink3.mk"
.include "../../geography/proj/buildlink3.mk"
.include "../../graphics/jasper/buildlink3.mk"
.include "../../mk/giflib.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
# See the comment above about using the internal tiff library
# also re-include in buildlink3.mk when uncommenting it!
# .include "../../graphics/tiff/buildlink3.mk"
.include "../../textproc/xerces-c/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
