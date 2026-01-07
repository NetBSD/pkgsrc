# $NetBSD: Makefile,v 1.39 2026/01/07 08:47:00 wiz Exp $

PKGREVISION= 5
.include "../../games/etlegacy/Makefile.common"

PKGNAME=	etlegacy-server-${ETL_VERSION}

COMMENT=	Open source Wolfenstein: Enemy Territory server

CMAKE_CONFIGURE_ARGS+=	-DBUILD_CLIENT=OFF

# Disable client-only features.
CMAKE_CONFIGURE_ARGS+=	-DFEATURE_OGG_VORBIS=OFF
CMAKE_CONFIGURE_ARGS+=	-DFEATURE_THEORA=OFF
CMAKE_CONFIGURE_ARGS+=	-DFEATURE_OPENAL=OFF
CMAKE_CONFIGURE_ARGS+=	-DFEATURE_FREETYPE=OFF
CMAKE_CONFIGURE_ARGS+=	-DFEATURE_RENDERER2=OFF

# Not set.
PLIST_VARS+=	client

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
