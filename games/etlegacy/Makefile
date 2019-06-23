# $NetBSD: Makefile,v 1.4 2019/06/23 11:20:23 maya Exp $

PKGNAME=	etlegacy-2.76
PKGREVISION=	2
CATEGORIES=	games

DIST_SUBDIR=	etlegacy-${PKGVERSION_NOREV}

DISTFILES+=	etlegacy.tar.gz
DISTFILES+=	etlegacy-libs.tar.gz

LIBS_TAG=	f04f846898a92d36fd9cfe7425b1ab4d31bca794

SITES.etlegacy.tar.gz= \
    -https://github.com/etlegacy/etlegacy/archive/v${PKGVERSION_NOREV}.tar.gz

SITES.etlegacy-libs.tar.gz= \
    -https://github.com/etlegacy/etlegacy-libs/archive/${LIBS_TAG}.tar.gz

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://www.etlegacy.com/
COMMENT=	Open source Wolfenstein: Enemy Territory client and server
LICENSE=	gnu-gpl-v3

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DRENDERER_DYNAMIC=OFF # doesn't work with builtin MesaLib
CMAKE_ARGS+=	-DFEATURE_RENDERER2=OFF # experimental, buggy

CMAKE_ARGS+=	-DBUNDLED_CURL=OFF
CMAKE_ARGS+=	-DBUNDLED_FREETYPE=OFF
CMAKE_ARGS+=	-DBUNDLED_GLEW=OFF
CMAKE_ARGS+=	-DBUNDLED_JPEG=OFF
CMAKE_ARGS+=	-DBUNDLED_LUA=OFF
CMAKE_ARGS+=	-DBUNDLED_OGG_VORBIS=OFF
CMAKE_ARGS+=	-DBUNDLED_OPENAL=OFF
CMAKE_ARGS+=	-DBUNDLED_OPENSSL=OFF
CMAKE_ARGS+=	-DBUNDLED_SDL=OFF
CMAKE_ARGS+=	-DBUNDLED_SQLITE3=OFF
CMAKE_ARGS+=	-DBUNDLED_THEORA=OFF
CMAKE_ARGS+=	-DBUNDLED_ZLIB=OFF

CMAKE_ARGS+=	-DCROSS_COMPILE32=OFF

CMAKE_ARGS+=	-DFEATURE_AUTOUPDATE=OFF

CMAKE_ARGS+=	-DFEATURE_OMNIBOT=OFF
CMAKE_ARGS+=	-DINSTALL_OMNIBOT=OFF

CMAKE_ARGS+=	-DFEATURE_OPENAL=ON

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE="Release"
CMAKE_ARGS+=	-DINSTALL_DEFAULT_BASEDIR="${PREFIX}/share/etlegacy"
CMAKE_ARGS+=	-DINSTALL_DEFAULT_BINDIR="bin"
CMAKE_ARGS+=	-DINSTALL_DEFAULT_MODDIR="share/etlegacy"

CFLAGS+=	-DIOAPI_NO_64

CHECK_PORTABILITY_SKIP+=	libs/sdl2/build-scripts/*

post-extract:
	${MV} ${WRKDIR}/etlegacy-libs-${LIBS_TAG}/* \
	    ${WRKDIR}/etlegacy-${PKGVERSION_NOREV}/libs

.include "options.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
