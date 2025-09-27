# $NetBSD: Makefile,v 1.31 2025/09/27 09:16:12 triaxx Exp $

DISTNAME=	corsix-th-0.69.1
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

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

USE_CXX_FEATURES+=	unique_ptr

.for module in AVCODEC AVFORMAT AVDEVICE AVUTIL SWSCALE POSTPROC SWRESAMPLE
CMAKE_CONFIGURE_ARGS+=	-D${module}_INCLUDE_DIRS=${BUILDLINK_PREFIX.ffmpeg7}/include/ffmpeg7
CMAKE_CONFIGURE_ARGS+=	-D${module}_LIBRARIES=${PREFIX}/lib/ffmpeg7/lib${module:tl}.${SHLIB_EXT}
.endfor

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
CHECK_SHLIBS_SUPPORTED=	no

MACOS_BUNDLE_DIR=	Applications
MACOS_BUNDLE_PREFIX=	${PREFIX}/${MACOS_BUNDLE_DIR}
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_INSTALL_PREFIX=${MACOS_BUNDLE_PREFIX}

# for CMake fixup_bundle() command
CMAKE_INSTALLED_BUNDLE_APP=	${DESTDIR}${MACOS_BUNDLE_PREFIX}/CorsixTH.app

SUBST_CLASSES+=		app
SUBST_STAGE.app=	pre-configure
SUBST_MESSAGE.app=	Fixing macOS app installation path.
SUBST_FILES.app=	CorsixTH/CMakeLists.txt
SUBST_VARS.app=		CMAKE_INSTALLED_BUNDLE_APP MACOS_BUNDLE_DIR

.include "../../lang/lua/module.mk"
PKGSRC_LUA_CPATH=	${PREFIX}/${LUA_CDIR}

SUBST_CLASSES+=		cpath
SUBST_STAGE.cpath=	pre-configure
SUBST_MESSAGE.cpath=	Fixing lpeg.dylib in package.cpatch.
SUBST_FILES.cpath=	CorsixTH/CorsixTH.lua
SUBST_VARS.cpath=	PKGSRC_LUA_CPATH

PLIST_SRC=		PLIST.bundle
.endif

.include "../../devel/cmake/build.mk"
.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/lua-lpeg/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../multimedia/ffmpeg7/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
