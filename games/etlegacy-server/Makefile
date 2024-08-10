# $NetBSD: Makefile,v 1.29 2024/08/10 11:12:16 nia Exp $

.include "../../games/etlegacy/Makefile.common"

PKGNAME=	etlegacy-server-${ETL_VERSION}

COMMENT=	Open source Wolfenstein: Enemy Territory server

CMAKE_ARGS+=	-DBUILD_CLIENT=OFF

# Disable client-only features.
CMAKE_ARGS+=	-DFEATURE_OGG_VORBIS=OFF
CMAKE_ARGS+=	-DFEATURE_THEORA=OFF
CMAKE_ARGS+=	-DFEATURE_OPENAL=OFF
CMAKE_ARGS+=	-DFEATURE_FREETYPE=OFF
CMAKE_ARGS+=	-DFEATURE_RENDERER2=OFF

# Not set.
PLIST_VARS+=	client

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
