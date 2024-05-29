# $NetBSD: Makefile,v 1.36 2024/05/29 16:32:42 adam Exp $

PKGNAME=		minetest-5.8.0
PKGREVISION=		3
CATEGORIES=		games
DIST_SUBDIR=		minetest-${PKGVERSION_NOREV}
DISTFILES+=		minetest.tar.gz

# This is a fork by the Minetest developers that was stripped-down and
# customized specifically for use in Minetest.
# It is intentionally not compatible to upstream and is planned to be
# eventually absorbed into Minetest.
# Repository: https://github.com/minetest/irrlicht
DISTFILES+=		irrlicht.tar.gz
IRRLICHT_VERSION=	1.9.0mt13
SITES.minetest.tar.gz=	\
	-https://github.com/minetest/minetest/archive/${PKGVERSION_NOREV}.tar.gz
SITES.irrlicht.tar.gz=	\
	-https://github.com/minetest/irrlicht/archive/${IRRLICHT_VERSION}.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.minetest.net/
COMMENT=	Infinite-world block sandbox with survival and crafting
LICENSE=	gnu-lgpl-v2.1 AND cc-by-sa-v3.0 AND apache-2.0

WRKSRC=		${WRKDIR}/minetest-${PKGVERSION_NOREV}

USE_CMAKE=	yes
USE_TOOLS+=	msgfmt
USE_LANGUAGES=	c c++

# "Insufficient gcc version, found 4.8.5.  Version 4.9 or higher is required."
GCC_REQD+=	4.9

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE="Release"

CMAKE_ARGS+=	-DBUILD_CLIENT=TRUE
CMAKE_ARGS+=	-DBUILD_SERVER=TRUE

CMAKE_ARGS+=	-DENABLE_POSTGRESQL=FALSE
CMAKE_ARGS+=	-DENABLE_LEVELDB=FALSE
CMAKE_ARGS+=	-DENABLE_REDIS=FALSE
CMAKE_ARGS+=	-DENABLE_SPATIAL=FALSE
#.include "../../lang/LuaJIT2/platform.mk"
#.if ${PLATFORM_SUPPORTS_LUAJIT} == "no"
#CMAKE_ARGS+=	-DENABLE_LUAJIT=FALSE
#.endif
# Binaries built with LuaJIT support have been broken since 2015, see:
# https://github.com/minetest/minetest/issues/2988
CMAKE_ARGS+=	-DENABLE_LUAJIT=FALSE
# As described above, use Minetest forked version of irrlicht.
#CMAKE_ARGS+=	-DIRRLICHT_INCLUDE_DIR=${BUILDLINK_PREFIX.irrlicht}/include/irrlicht

post-extract:
	${MV} ${WRKDIR}/irrlicht-${IRRLICHT_VERSION} \
	    ${WRKSRC}/lib/irrlichtmt


.include "../../archivers/bzip2/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../archivers/zstd/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
#.include "../../graphics/irrlicht/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../textproc/jsoncpp/buildlink3.mk"
#.if ${PLATFORM_SUPPORTS_LUAJIT} != "no"
#.include "../../lang/LuaJIT2/buildlink3.mk"
#.endif
.include "../../www/curl/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
