# $NetBSD: Makefile,v 1.15 2020/06/19 13:06:35 nia Exp $

DISTNAME=	mgba-0.8.2
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=mgba-emu/}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://mgba.io/
COMMENT=	Emulator for running Game Boy Advance games
LICENSE=	mpl-2.0

USE_TOOLS+=	pkg-config
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

# C++14
GCC_REQD+=	5

CMAKE_ARGS+=	-DUSE_DISCORD_RPC=OFF
CMAKE_ARGS+=	-DUSE_MINIZIP=OFF # using libzip

.include "options.mk"
.include "../../archivers/libzip/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/libelf/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
