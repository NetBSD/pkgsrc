# $NetBSD: Makefile,v 1.18 2020/06/02 08:22:42 adam Exp $

DISTNAME=	libspatialite-4.3.0a
PKGREVISION=	12
CATEGORIES=	geography
MASTER_SITES=	http://www.gaia-gis.it/gaia-sins/

MAINTAINER=	pkgsrc@NetBSD.org
HOMEPAGE=	https://www.gaia-gis.it/fossil/libspatialite/
COMMENT=	Library intended to extend SQLite core to support Spatial SQL
LICENSE=	gnu-gpl-v2 OR gnu-lgpl-v2.1

USE_LANGUAGES=		c
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-examples
PKGCONFIG_OVERRIDE=	spatialite.pc.in

# https://www.gaia-gis.it/fossil/libspatialite/tktview?name=6eabdf0e6d
CPPFLAGS+=	-DACCEPT_USE_OF_DEPRECATED_PROJ_API_H

# src/shapefiles wants to create both a module and library
# from the same sources. This confuses some temporary file handling
# in libtool 2.4.2.
MAKE_JOBS_SAFE=	no

.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../geography/geos/buildlink3.mk"
.include "../../geography/proj/buildlink3.mk"
.include "../../textproc/freexl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
