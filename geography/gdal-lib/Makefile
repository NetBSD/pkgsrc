# $NetBSD: Makefile,v 1.30 2010/08/27 11:14:23 adam Exp $

DISTNAME=	gdal-1.7.2
PKGNAME=	gdal-lib-1.7.2
CATEGORIES=	geography
MASTER_SITES=	http://download.osgeo.org/gdal/

MAINTAINER=	brook@nmsu.edu
HOMEPAGE=	http://www.gdal.org/
COMMENT=	Translator library for raster geospatial data formats
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++ fortran
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-geos
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
.include "../../graphics/libungif/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../textproc/xerces-c/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
