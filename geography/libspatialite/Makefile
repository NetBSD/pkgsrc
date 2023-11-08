# $NetBSD: Makefile,v 1.32 2023/11/08 13:19:24 wiz Exp $

DISTNAME=	libspatialite-5.0.1
PKGREVISION=	4
CATEGORIES=	geography
MASTER_SITES=	http://www.gaia-gis.it/gaia-sins/

MAINTAINER=	pkgsrc@NetBSD.org
HOMEPAGE=	https://www.gaia-gis.it/fossil/libspatialite/
COMMENT=	Library intended to extend SQLite core to support Spatial SQL
LICENSE=	mpl-1.1 OR gnu-gpl-v2 OR gnu-lgpl-v2.1 # or later GPL or LGPL

USE_LANGUAGES=		c
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-examples
PKGCONFIG_OVERRIDE=	spatialite.pc.in

.include "../../archivers/minizip/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
BUILDLINK_API_DEPENDS.sqlite3+=	sqlite3>=3.33.0
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../geography/geos/buildlink3.mk"
.include "../../geography/librttopo/buildlink3.mk"
.include "../../geography/proj/buildlink3.mk"
.include "../../textproc/freexl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
