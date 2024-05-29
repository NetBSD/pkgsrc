# $NetBSD: Makefile,v 1.60 2024/05/29 16:31:23 adam Exp $

DISTNAME=	mixxx-2.3.1
PKGREVISION=	31
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=mixxxdj/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://mixxx.org/
COMMENT=	DJ mixing application
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

USE_CMAKE=	yes

CMAKE_ARGS+=	-DUSE_SYMLINKS=OFF
CMAKE_ARGS+=	-DPORTMIDI=OFF

USE_CXX_FEATURES+=	c++11

.include "../../mk/bsd.prefs.mk"

REPLACE_INTERPRETER+=	node
REPLACE.node.old=	.*/usr/bin/env node
REPLACE.node.new=	${PREFIX}/bin/node
REPLACE_FILES.node+=	res/controllers/novation-launchpad/scripts/compile-mapping.js
REPLACE_FILES.node+=	res/controllers/novation-launchpad/scripts/compile-scripts.js

# avoid a hard nodejs dependency
CHECK_INTERPRETER_SKIP+=	share/mixxx/controllers/novation-launchpad/scripts/*

.include "../../audio/chromaprint/buildlink3.mk"
.include "../../audio/faad2/buildlink3.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../audio/lame/buildlink3.mk"
.include "../../audio/libebur128/buildlink3.mk"
.include "../../audio/libid3tag/buildlink3.mk"
.include "../../audio/libkeyfinder/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libmodplug/buildlink3.mk"
.include "../../audio/libshout/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/lilv/buildlink3.mk"
.include "../../audio/lv2/buildlink3.mk"
.include "../../audio/opusfile/buildlink3.mk"
.include "../../audio/portaudio/buildlink3.mk"
.include "../../audio/rubberband/buildlink3.mk"
.include "../../audio/soundtouch/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../audio/wavpack/buildlink3.mk"
.include "../../comms/libhidapi/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../devel/protobuf/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.include "../../multimedia/mp4v2/buildlink3.mk"
.include "../../security/qt5-qtkeychain/buildlink3.mk"
.include "../../sysutils/upower/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtscript/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
