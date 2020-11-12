# $NetBSD: Makefile,v 1.16 2020/11/12 03:34:07 gutteridge Exp $

DISTNAME=	musescore-3.5.2
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=musescore/}
GITHUB_PROJECT=	MuseScore
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://musescore.org/
COMMENT=	Music notation and composition software
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++11

# C++11
GCC_REQD+=	4.8

CONFIGURE_DIRS=	bindir
CMAKE_ARG_PATH=	..

CMAKE_ARGS+=	-Wno-dev
CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE="Release"
CMAKE_ARGS+=	-DMUSESCORE_BUILD_CONFIG=release
CMAKE_ARGS+=	-DUSE_SYSTEM_FREETYPE=ON
CMAKE_ARGS+=	-DDOWNLOAD_SOUNDFONT=OFF
CMAKE_ARGS+=	-DBUILD_PCH=OFF
CMAKE_ARGS+=	-DBUILD_PORTMIDI=OFF
CMAKE_ARGS+=	-DBUILD_TELEMETRY_MODULE=OFF
CMAKE_ARGS+=	-DBUILD_WEBENGINE=OFF

pre-configure:
	${MKDIR} ${WRKSRC}/bindir

DEPENDS+=	qt5-qttranslations>=5.15.1:../../x11/qt5-qttranslations

.include "options.mk"
.include "../../audio/lame/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
BUILDLINK_API_DEPENDS.qt5-qtbase+=      qt5-qtbase>=5.15.1
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../x11/qt5-qtquickcontrols2/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../x11/qt5-qtxmlpatterns/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
