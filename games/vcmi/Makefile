# $NetBSD: Makefile,v 1.23 2026/05/07 17:16:19 adam Exp $

DISTNAME=	vcmi-1.7.3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=vcmi/}

GITHUB_SUBMODULES+=	vcmi innoextract \
			96e9566a35fb51ebf13ffbdadfd49a93c1ae5c1a \
			launcher/lib/innoextract

GITHUB_SUBMODULES+=	fuzzylite fuzzylite \
			13b3122f5c353c0389ed4e66041d548c44ec9df6 \
			AI/FuzzyLite

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://vcmi.eu/
COMMENT=	Open-source engine for Heroes of Might and Magic III
LICENSE=	gnu-gpl-v2

USE_CXX_FEATURES=	c++17
USE_LANGUAGES=		c c++
USE_TOOLS+=		bash:run pkg-config

LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/vcmi

CMAKE_CONFIGURE_ARGS+=	-DENABLE_DISCORD=OFF
CMAKE_CONFIGURE_ARGS+=	-DENABLE_MMAI=OFF # needs onnxruntime
CMAKE_CONFIGURE_ARGS+=	-DFORCE_BUNDLED_FL=ON

TOOL_DEPENDS+=	qt5-qttools-[0-9]*:../../x11/qt5-qttools

# lie to the compiler
CXXFLAGS+=	-DBOOST_STACKTRACE_GNU_SOURCE_NOT_REQUIRED

SUBST_CLASSES+=		ffmpeg
SUBST_FILES.ffmpeg+=	cmake_modules/Findffmpeg.cmake
SUBST_SED.ffmpeg+=	-e "s,/opt/include,${BUILDLINK_DIR}/include/ffmpeg8,"
SUBST_SED.ffmpeg+=	-e "s,/opt/lib,${BUILDLINK_DIR}/lib/ffmpeg8,"
SUBST_MESSAGE.ffmpeg=	Helping cmake find ffmpeg.
SUBST_STAGE.ffmpeg=	pre-configure

SUBST_CLASSES+=		squish
SUBST_FILES.squish+=	cmake_modules/Findlibsquish.cmake
SUBST_SED.squish+=	-e "s,/usr/local/include,${BUILDLINK_DIR}/include,"
SUBST_SED.squish+=	-e "s,/usr/local/lib,${BUILDLINK_DIR}/lib,"
SUBST_MESSAGE.squish=	Helping cmake find libsquish.
SUBST_STAGE.squish=	pre-configure

.include "../../mk/compiler.mk"

.if ${CC_VERSION:Mgcc-*}
CMAKE_CONFIGURE_ARGS+=	-DENABLE_PCH=OFF
.endif

.include "../../mk/bsd.fast.prefs.mk"
LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/vcmi

REPLACE_BASH+=	vcmibuilder

PYTHON_FOR_BUILD_ONLY=		tool

CHECK_PORTABILITY_SKIP+=	CI/get_package_name.sh

PLIST_VARS+=	desktop
.if ${OPSYS} != "Darwin"
PLIST.desktop=	yes
.endif

.include "options.mk"

.include "../../archivers/minizip/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../fonts/SDL2_ttf/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/libsquish/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../multimedia/ffmpeg8/buildlink3.mk"
.include "../../parallel/threadingbuildingblocks/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
