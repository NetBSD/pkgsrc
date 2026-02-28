# $NetBSD: Makefile,v 1.69 2026/02/28 16:53:58 gutteridge Exp $

DISTNAME=	musescore-4.6.5
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=musescore/}
GITHUB_PROJECT=	MuseScore
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	gutteridge@NetBSD.org
HOMEPAGE=	https://musescore.org/
COMMENT=	Music notation and composition software
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		pkg-config
USE_LANGUAGES=		c c++
USE_CXX_FEATURES=	c++17
# GCC 9 (present minimum due to Qt6 enforcing this) has an issue
# handling a lambda expression, which GCC 10 and newer are fine with.
GCC_REQD+=		10

DEPENDS+=	qt6-qttranslations-[0-9]*:../../x11/qt6-qttranslations

CONFIGURE_DIRS=	bindir
CMAKE_ARG_PATH=	..

CMAKE_CONFIGURE_ARGS+=	-Wno-dev
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE="Release"
CMAKE_CONFIGURE_ARGS+=	-DMUSESCORE_BUILD_CONFIGURATION=app
CMAKE_CONFIGURE_ARGS+=	-DMUE_DOWNLOAD_SOUNDFONT=OFF
CMAKE_CONFIGURE_ARGS+=	-DSKIP_PRECOMPILE_HEADERS=ON

CMAKE_CONFIGURE_ARGS+=	-DMUE_COMPILE_USE_SYSTEM_FLAC=ON
CMAKE_CONFIGURE_ARGS+=	-DMUE_COMPILE_USE_SYSTEM_FREETYPE=ON
CMAKE_CONFIGURE_ARGS+=	-DMUE_COMPILE_USE_SYSTEM_HARFBUZZ=ON
CMAKE_CONFIGURE_ARGS+=	-DMUE_COMPILE_USE_SYSTEM_OPUS=ON
CMAKE_CONFIGURE_ARGS+=	-DMUE_COMPILE_USE_SYSTEM_OPUSENC=ON
CMAKE_CONFIGURE_ARGS+=	-DMUE_COMPILE_USE_SYSTEM_TINYXML=ON

pre-configure:
	${MKDIR} ${WRKSRC}/bindir

.include "options.mk"

.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../audio/mpg123/buildlink3.mk"
.include "../../audio/libopus/buildlink3.mk"
.include "../../audio/libopusenc/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/qt6-qt5compat/buildlink3.mk"
# This should really be a tool dependency, but there are complications.
.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../lang/qt6-qtscxml/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../security/qt6-qtnetworkauth/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/tinyxml2/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
