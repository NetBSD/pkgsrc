# $NetBSD: Makefile,v 1.10 2020/03/20 17:06:20 nia Exp $

PKGNAME=	minetest-5.1.1
CATEGORIES=	games
DIST_SUBDIR=	minetest-${PKGVERSION_NOREV}
DISTFILES+=	minetest.tar.gz
DISTFILES+=	minetest-game.tar.gz
SITES.minetest.tar.gz=\
	-https://github.com/minetest/minetest/archive/${PKGVERSION_NOREV}.tar.gz
SITES.minetest-game.tar.gz=\
	-https://github.com/minetest/minetest_game/archive/${PKGVERSION_NOREV}.tar.gz

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://www.minetest.net/
COMMENT=	Infinite-world block sandbox with survival and crafting
LICENSE=	gnu-lgpl-v2.1 AND cc-by-sa-v3.0 AND apache-2.0

WRKSRC=		${WRKDIR}/minetest-${PKGVERSION_NOREV}

USE_CMAKE=	yes
USE_TOOLS+=	msgfmt
USE_LANGUAGES=	c c++11

# "Insufficient gcc version, found 4.8.5.  Version 4.9 or higher is required."
GCC_REQD+=	4.9

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE="Release"

CMAKE_ARGS+=	-DBUILD_CLIENT=TRUE
CMAKE_ARGS+=	-DBUILD_SERVER=TRUE

CMAKE_ARGS+=	-DENABLE_POSTGRESQL=FALSE
CMAKE_ARGS+=	-DENABLE_LEVELDB=FALSE
CMAKE_ARGS+=	-DENABLE_REDIS=FALSE
CMAKE_ARGS+=	-DENABLE_SPATIAL=FALSE
CMAKE_ARGS+=	-DENABLE_LUAJIT=FALSE

CMAKE_ARGS+=	-DIRRLICHT_INCLUDE_DIR=${BUILDLINK_PREFIX.irrlicht}/include/irrlicht

post-extract:
	${MV} ${WRKDIR}/minetest_game-${PKGVERSION_NOREV} \
	    ${WRKSRC}/games/minetest_game

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/ncursesw/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/irrlicht/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
