# $NetBSD: Makefile,v 1.3 2020/06/29 14:59:26 nia Exp $

DISTNAME=	corsix-th-0.64
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=CorsixTH/}
GITHUB_PROJECT=	CorsixTH
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/CorsixTH/CorsixTH
COMMENT=	Reimplementation of the game engine of Theme Hospital
LICENSE=	mit

DEPENDS+=	lua53-filesystem-[0-9]*:../../devel/lua-filesystem
DEPENDS+=	lua53-lpeg-[0-9]*:../../devel/lua-lpeg

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

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
.include "../../lang/lua53/buildlink3.mk"
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
