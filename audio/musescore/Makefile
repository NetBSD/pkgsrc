# $NetBSD: Makefile,v 1.1 2019/10/16 23:22:08 nia Exp $

DISTNAME=	musescore-3.2.3
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
GCC_REQD+=	4.7

CONFIGURE_DIRS=	bindir
CMAKE_ARG_PATH=	..

CMAKE_ARGS+=	-Wno-dev
CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE="Release"
CMAKE_ARGS+=	-DUSE_SYSTEM_FREETYPE=ON
CMAKE_ARGS+=	-DDOWNLOAD_SOUNDFONT=OFF
CMAKE_ARGS+=	-DBUILD_PCH=OFF
CMAKE_ARGS+=	-DBUILD_PORTMIDI=OFF
CMAKE_ARGS+=	-DBUILD_WEBENGINE=OFF

pre-configure:
	${MKDIR} ${WRKSRC}/bindir

.include "options.mk"
.include "../../audio/lame/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../x11/qt5-qtxmlpatterns/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
