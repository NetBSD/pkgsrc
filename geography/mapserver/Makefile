# $NetBSD: Makefile,v 1.51 2014/02/12 23:17:58 tron Exp $

DISTNAME=	mapserver-5.6.8
PKGREVISION=	15
CATEGORIES=	geography www
MASTER_SITES=	http://download.osgeo.org/mapserver/

MAINTAINER=	hdp@cs.msu.edu
HOMEPAGE=	http://mapserver.org/
COMMENT=	Environment for building spatially enabled Internet apps

MAKE_JOBS_SAFE=		no

USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-cairo
CONFIGURE_ARGS+=	--with-freetype
CONFIGURE_ARGS+=	--with-gdal
CONFIGURE_ARGS+=	--with-gd=${BUILDLINK_PREFIX.gd}
CONFIGURE_ARGS+=	--with-geos
CONFIGURE_ARGS+=	--with-libiconv
CONFIGURE_ARGS+=	--with-ogr
CONFIGURE_ARGS+=	--with-png
CONFIGURE_ARGS+=	--with-proj
CONFIGURE_ARGS+=	--with-wcs
CONFIGURE_ARGS+=	--with-wfs
CONFIGURE_ARGS+=	--with-zlib

INSTALLATION_DIRS=	bin lib libexec/cgi-bin

do-install:
	${INSTALL_DATA} ${WRKSRC}/libmapserver.a ${DESTDIR}${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/mapserv ${DESTDIR}${PREFIX}/libexec/cgi-bin
.for f in legend msencrypt scalebar shp2img shp2pdf \
	shptree shptreetst shptreevis sortshp tile4ms
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/bin
.endfor

.include "options.mk"

.include "../../converters/fribidi/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../geography/gdal-lib/buildlink3.mk"
.include "../../geography/geos/buildlink3.mk"
.include "../../geography/proj/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/gd/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
