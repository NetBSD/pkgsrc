# $NetBSD: Makefile,v 1.43 2024/05/29 16:33:46 adam Exp $

DISTNAME=	olive-editor-0.2.0pre20230924
PKGREVISION=	12
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=olive-editor/}
GITHUB_PROJECT=	olive
GITHUB_TAG=	55eedbfce909dfd7df97611a2eea1d1958385f9c

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://olivevideoeditor.org/
COMMENT=	Non-linear video editor
LICENSE=	gnu-gpl-v3

GITHUB_SUBMODULES+=	olive-editor core 277792824801495e868580ca86f6e7a1b53e4779 ext/core
GITHUB_SUBMODULES+=	olive-editor KDDockWidgets 8d2d0a5764f8393cc148a2296d511276a8ffe559 ext/KDDockWidgets

TOOL_DEPENDS+=	qt5-qttools-[0-9]*:../../x11/qt5-qttools

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

USE_CXX_FEATURES+=	c++11

CMAKE_ARGS+=	-DFFMPEG_INCLUDE_ROOT=${BUILDLINK_DIR}/include/ffmpeg6
CMAKE_ARGS+=	-DFFMPEG_LIB_ROOT=${BUILDLINK_DIR}/lib/ffmpeg6
CMAKE_ARGS+=	-DPORTAUDIO_INCLUDE_DIR=${BUILDLINK_DIR}/include/portaudio2
CMAKE_ARGS+=	-DPORTAUDIO_LIBRARY=${BUILDLINK_DIR}/lib/portaudio2/libportaudiocpp.so

.include "../../audio/portaudio/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/opencolorio/buildlink3.mk"
.include "../../graphics/openimageio/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../multimedia/ffmpeg6/buildlink3.mk"
.include "../../multimedia/frei0r/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtmultimedia/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
