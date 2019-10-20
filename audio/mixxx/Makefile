# $NetBSD: Makefile,v 1.8 2019/10/20 11:10:47 nia Exp $

DISTNAME=	mixxx-2.2.2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=mixxxdj/}
GITHUB_TAG=	release-${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://mixxx.org/
COMMENT=	DJ mixing application
LICENSE=	gnu-gpl-v2

.include "../../mk/bsd.prefs.mk"

USE_LANGUAGES=	c c++11
USE_TOOLS+=	pkg-config

# c++11
GCC_REQD+=	4.9

PLIST_SRCS+=	PLIST

SCONS_ARGS+=	-j${MAKE_JOBS:U1}

# scons fails otherwise
PYTHON_VERSIONS_ACCEPTED=	27

CHECK_PORTABILITY_SKIP+=	lib/gmock-1.7.0/configure

# No support in the build system.
BROKEN_ON_PLATFORM+=	SunOS-*-*

SUBST_CLASSES+=		base
SUBST_STAGE.base=	pre-configure
SUBST_FILES.base=	build/depends.py
SUBST_VARS.base=	LOCALBASE

SCONS_ARGS+=	faad=1
SCONS_ARGS+=	modplug=1

SCONS_ARGS+=	build="release"

# let pkgsrc take care of this
SCONS_ARGS+=	optimize="off"

# XXX horrible workaround
CXXFLAGS+=	-I${QTDIR}/include/QtConcurrent
CXXFLAGS+=	-I${QTDIR}/include/QtCore
CXXFLAGS+=	-I${QTDIR}/include/QtDBus
CXXFLAGS+=	-I${QTDIR}/include/QtGui
CXXFLAGS+=	-I${QTDIR}/include/QtNetwork
CXXFLAGS+=	-I${QTDIR}/include/QtOpenGL
CXXFLAGS+=	-I${QTDIR}/include/QtScript
CXXFLAGS+=	-I${QTDIR}/include/QtScriptTools
CXXFLAGS+=	-I${QTDIR}/include/QtSql
CXXFLAGS+=	-I${QTDIR}/include/QtSvg
CXXFLAGS+=	-I${QTDIR}/include/QtWidgets
CXXFLAGS+=	-I${QTDIR}/include/QtXml

REPLACE_INTERPRETER+=	node
REPLACE.node.old=	.*/usr/bin/env node
REPLACE.node.new=	${PREFIX}/bin/node
REPLACE_FILES.node+=	res/controllers/novation-launchpad/scripts/compile-mapping.js
REPLACE_FILES.node+=	res/controllers/novation-launchpad/scripts/compile-scripts.js

# avoid a hard nodejs dependency
CHECK_INTERPRETER_SKIP+=	share/mixxx/controllers/novation-launchpad/scripts/*

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${SCONSBIN} ${SCONS_ARGS} \
            CC=${CC:Q} CXX=${CXX:Q} CFLAGS=${CFLAGS:Q} CXXFLAGS=${CXXFLAGS:Q} \
            LINKFLAGS=${LDFLAGS:Q} qtdir=${QTDIR:Q} prefix=${PREFIX}
do-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${SCONSBIN} ${SCONS_ARGS} \
            CC=${CC:Q} CXX=${CXX:Q} CFLAGS=${CFLAGS:Q} CXXFLAGS=${CXXFLAGS:Q} \
            LINKFLAGS=${LDFLAGS:Q} qtdir=${QTDIR:Q} prefix=${PREFIX} install \
	    --install-sandbox=${DESTDIR}

.include "options.mk"
.include "../../audio/chromaprint/buildlink3.mk"
.include "../../audio/faad2/buildlink3.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../audio/libebur128/buildlink3.mk"
.include "../../audio/libid3tag/buildlink3.mk"
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
.include "../../audio/vamp-plugin-sdk/buildlink3.mk"
.include "../../comms/libhidapi/buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../devel/protobuf/buildlink3.mk"
.include "../../devel/scons/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../multimedia/mp4v2/buildlink3.mk"
.include "../../sysutils/upower/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtscript/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
