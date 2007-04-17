# $NetBSD: Makefile,v 1.10 2007/04/17 01:04:44 gdt Exp $
#

DISTNAME=		gdal-1.4.0
PKGNAME=		gdal-lib-1.4.0
PKGREVISION=		2
CATEGORIES=		geography
MASTER_SITES=		http://www.gdal.org/dl/

MAINTAINER=		brook@nmsu.edu
HOMEPAGE=		http://www.gdal.org/
COMMENT=		Translator library for raster geospatial data formats

MAKE_JOBS_SAFE=		no

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++ fortran
USE_LIBTOOL=		yes

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

MAKE_FILE=		GNUmakefile

PKG_OPTIONS_VAR=	PKG_OPTIONS.gdal-lib
PKG_SUPPORTED_OPTIONS=	pgsql mysql
PKG_SUGGESTED_OPTIONS=	pgsql

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpgsql)
. include "../../mk/pgsql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-pg
.else
CONFIGURE_ARGS+=	--without-pg
.endif

.if !empty(PKG_OPTIONS:Mmysql)
. include "../../mk/mysql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-mysql
.else
CONFIGURE_ARGS+=	--without-mysql
.endif

CONFIGURE_ARGS+=	--with-xerces
CONFIGURE_ARGS+=	--with-xerces-inc=${PREFIX:Q}/include
CONFIGURE_ARGS+=	--with-xerces-lib=-L${PREFIX:Q}/lib\ -lxerces-c
CONFIGURE_ARGS+=	--with-geos
CONFIGURE_ARGS+=	--without-python

CHECK_PORTABILITY_SKIP+=	mkbindist.sh

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../geography/geos/buildlink3.mk"
.include "../../misc/proj/buildlink3.mk"
.include "../../textproc/xerces-c/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
