# $NetBSD: Makefile,v 1.79 2016/03/05 11:27:47 jperkin Exp $

DISTNAME=	gdal-1.11.3
PKGNAME=	${DISTNAME:S/gdal/gdal-lib/}
PKGREVISION=	2
CATEGORIES=	geography
MASTER_SITES=	http://download.osgeo.org/gdal/${PKGVERSION_NOREV}/

MAINTAINER=	brook@nmsu.edu
HOMEPAGE=	http://www.gdal.org/
COMMENT=	Translator library for raster geospatial data formats
LICENSE=	mit

# This package links against the geos C++ library.  geos regards this
# as a bug and changes the C++ shlib version every release.  Therefore
# this package needs revbumping on every geos update.

USE_LANGUAGES=		c99 c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-geos
CONFIGURE_ARGS+=	--with-libjson-c=internal
CONFIGURE_ARGS+=	--with-libtiff=${BUILDLINK_PREFIX.tiff}
CONFIGURE_ARGS+=	--with-libz=${BUILDLINK_PREFIX.zlib}/include
CONFIGURE_ARGS+=	--with-netcdf=${BUILDLINK_PREFIX.netcdf}
CONFIGURE_ARGS+=	--with-webp=${BUILDLINK_PREFIX.libwebp}
CONFIGURE_ARGS+=	--with-xerces
CONFIGURE_ARGS+=	--with-xerces-inc=${BUILDLINK_PREFIX.xerces-c}/include
CONFIGURE_ARGS+=	--with-xerces-lib=-L${BUILDLINK_PREFIX.xerces-c}/lib\ -lxerces-c
CONFIGURE_ARGS+=	--without-python

MAKE_FILE=		GNUmakefile

.include "options.mk"

CHECK_PORTABILITY_SKIP+=	mkbindist.sh

INSTALLATION_DIRS=	bin include lib ${PKGMANDIR}/man1 share/gdal

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
