# $NetBSD: Makefile,v 1.4 2006/09/09 02:42:01 obache Exp $
#

DISTNAME=		gdal-1.3.1
PKGNAME=		gdal-lib-1.3.1
CATEGORIES=		geography
MASTER_SITES=		http://www.gdal.org/dl/

MAINTAINER=		mchittur@cs.nmsu.edu
HOMEPAGE=		http://gdal.org/
COMMENT=		Translator library for raster geospatial data formats

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

MAKE_FILE=		GNUmakefile

PKG_OPTIONS_VAR=	PKG_OPTIONS.gdal-lib
PKG_SUPPORTED_OPTIONS=	pgsql
PKG_SUGGESTED_OPTIONS=	pgsql

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpgsql)
. include "../../mk/pgsql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-pg
.else
CONFIGURE_ARGS+=	--without-pg
.endif

CONFIGURE_ARGS+=	--with-xerces
CONFIGURE_ARGS+=	--with-xerces-inc=${PREFIX:Q}/include
CONFIGURE_ARGS+=	--with-xerces-lib=-L${PREFIX:Q}/lib\ -lxerces-c
CONFIGURE_ARGS+=	--with-geos
CONFIGURE_ARGS+=	--without-python

.include "../../devel/zlib/buildlink3.mk"
.include "../../misc/proj/buildlink3.mk"
.include "../../geography/geos/buildlink3.mk"
.include "../../textproc/xerces-c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
