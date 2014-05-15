# $NetBSD: Makefile,v 1.66 2014/05/15 14:41:50 adam Exp $

VERSION=	1.9.2
DISTNAME=	gdal-${VERSION}
PKGNAME=	gdal-lib-${VERSION}
PKGREVISION=	9
CATEGORIES=	geography
MASTER_SITES=	http://download.osgeo.org/gdal/

MAINTAINER=	brook@nmsu.edu
HOMEPAGE=	http://www.gdal.org/
COMMENT=	Translator library for raster geospatial data formats
LICENSE=	mit

# This package links against the geos C++ library.  geos regards this
# as a bug and changes the C++ shlib version every release.  Therefore
# this package needs revbumping on every geos update.

# There is mysterious failure to find gdal_version.h, even though it
# is not a generated file, apparently caused by an odd make path that
# fails to use the right includes.
MAKE_JOBS_SAFE=		no

USE_LANGUAGES=		c c++ fortran77
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-geos
CONFIGURE_ARGS+=	--with-libtiff=${BUILDLINK_PREFIX.tiff}
CONFIGURE_ARGS+=	--with-libz=${BUILDLINK_PREFIX.zlib}/include
CONFIGURE_ARGS+=	--with-netcdf=${BUILDLINK_PREFIX.netcdf}
CONFIGURE_ARGS+=	--with-xerces
CONFIGURE_ARGS+=	--with-xerces-inc=${BUILDLINK_PREFIX.xerces-c}/include
CONFIGURE_ARGS+=	--with-xerces-lib=-L${BUILDLINK_PREFIX.xerces-c}/lib\ -lxerces-c
CONFIGURE_ARGS+=	--without-python

MAKE_FILE=		GNUmakefile

.include "options.mk"

CHECK_PORTABILITY_SKIP+=	mkbindist.sh

INSTALLATION_DIRS=	bin include lib ${PKGMANDIR}/man1 share/gdal

.include "../../devel/netcdf/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../geography/geos/buildlink3.mk"
.include "../../geography/proj/buildlink3.mk"
.include "../../graphics/jasper/buildlink3.mk"
.include "../../mk/giflib.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../textproc/xerces-c/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
