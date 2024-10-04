# $NetBSD: Makefile,v 1.4 2024/10/04 03:49:24 ryoon Exp $

DISTNAME=	vcmi-1.5.6
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=vcmi/}

GITHUB_SUBMODULES+=	vcmi innoextract \
			9977089412ebafe9f79936aa65a2edf16a84ae3e \
			launcher/lib/innoextract

GITHUB_SUBMODULES+=	fuzzylite fuzzylite \
			7aee562d6ca17f3cf42588ffb5116e03017c3c50 \
			AI/FuzzyLite

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://vcmi.eu/
COMMENT=	Open-source engine for Heroes of Might and Magic III
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config bash:run

TOOL_DEPENDS+=	qt5-qttools-[0-9]*:../../x11/qt5-qttools

USE_CXX_FEATURES+=	c++17

.include "../../mk/compiler.mk"

.if ${CC_VERSION:Mgcc-*}
CMAKE_CONFIGURE_ARGS+=	-DENABLE_PCH=OFF
.endif

.include "../../mk/bsd.fast.prefs.mk"

LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/vcmi

REPLACE_BASH+=	vcmibuilder

PYTHON_FOR_BUILD_ONLY=		tool

CHECK_PORTABILITY_SKIP+=	CI/get_package_name.sh

.include "options.mk"
.include "../../devel/cmake/build.mk"
.include "../../archivers/minizip/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../fonts/SDL2_ttf/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../lang/python/pyversion.mk"
.include "../../multimedia/ffmpeg7/buildlink3.mk"
.include "../../parallel/threadingbuildingblocks/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
