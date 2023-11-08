# $NetBSD: Makefile,v 1.50 2023/11/08 13:19:20 wiz Exp $

DISTNAME=	openrct2-0.4.6
PKGREVISION=	3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=OpenRCT2/}
GITHUB_PROJECT=	OpenRCT2
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/OpenRCT2/OpenRCT2/
COMMENT=	Open source reimplementation of RollerCoaster Tycoon 2
LICENSE=	gnu-gpl-v3

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++17

# C++17
GCC_REQD+=	9

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE="Release"
CMAKE_ARGS+=	-DCMAKE_CXX_COMPILER_AR="/usr/bin/ar"
CMAKE_ARGS+=	-DDISABLE_DISCORD_RPC=ON
CMAKE_ARGS+=	-DDISABLE_GOOGLE_BENCHMARK=ON
CMAKE_ARGS+=	-DMACOS_USE_DEPENDENCIES=OFF
CMAKE_ARGS+=	-DMACOS_BUNDLE=OFF

CXXFLAGS+=	-DORCT2_RESOURCE_DIR=\"${PREFIX}/share/openrct2\"

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..

BUILDLINK_TRANSFORM+=	rm:-Werror

# XXX it cannot be built without an Internet connection.
# Fails during install stage:
# CMake Error at cmake_install.cmake:48 (file):
#  file DOWNLOAD HASH mismatch
#
#    for file: [/wrk/games/openrct2/work/.destdir/p/share/openrct2/title/title-sequences.zip]
#      expected hash: [304d13a126c15bf2c86ff13b81a2f2cc1856ac8d]
#        actual hash: [da39a3ee5e6b4b0d3255bfef95601890afd80709]
#             status: [6;"Couldn't resolve host name"]
#

SUBST_CLASSES+=		doc
SUBST_STAGE.doc=	pre-configure
SUBST_MESSAGE.doc=	Fixing documentation path.
SUBST_FILES.doc=	src/openrct2/platform/Platform.macOS.mm
SUBST_VARS.doc=		PREFIX

pre-configure:
	${MKDIR} ${WRKSRC}/build

.include "../../archivers/libzip/buildlink3.mk"
.include "../../audio/speexdsp/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/libduktape/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/nlohmann-json/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
