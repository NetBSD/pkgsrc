# $NetBSD: Makefile,v 1.21 2024/01/30 14:21:53 ryoon Exp $

DISTNAME=	corsix-th-0.67
PKGREVISION=	3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=CorsixTH/}
GITHUB_PROJECT=	CorsixTH
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/CorsixTH/CorsixTH
COMMENT=	Reimplementation of the game engine of Theme Hospital
LICENSE=	mit

LUA_VERSIONS_ACCEPTED=	54 53 52 51

.include "../../lang/lua/luaversion.mk"

DEPENDS+=	${LUA_PKGPREFIX}-filesystem-[0-9]*:../../devel/lua-filesystem
DEPENDS+=	${LUA_PKGPREFIX}-lpeg-[0-9]*:../../devel/lua-lpeg

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

USE_CXX_FEATURES+=	unique_ptr

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
SOEXT=	dylib
.else
SOEXT=	so
.endif

.for module in AVCODEC AVFORMAT AVDEVICE AVUTIL SWSCALE POSTPROC SWRESAMPLE
CMAKE_ARGS+=	-D${module}_INCLUDE_DIRS=${BUILDLINK_PREFIX.ffmpeg4}/include/ffmpeg4
CMAKE_ARGS+=	-D${module}_LIBRARIES=${PREFIX}/lib/ffmpeg4/lib${module:tl}.${SOEXT}
.endfor

.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
