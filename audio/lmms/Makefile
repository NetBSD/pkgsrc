# $NetBSD: Makefile,v 1.62 2020/06/02 08:23:13 adam Exp $

DISTNAME=	lmms_1.2.1
PKGNAME=	${DISTNAME:S/_/-/1}
PKGREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=LMMS/}
GITHUB_PROJECT=	lmms
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://lmms.io/
COMMENT=	Cross-platform music production software
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	qt5-qttools-[0-9]*:../../x11/qt5-qttools

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++03

.include "../../mk/oss.buildlink3.mk"

.if ${OSS_TYPE} != "none"
LDFLAGS+=	${LIBOSSAUDIO}
.endif

CMAKE_ARGS+=	-Wno-dev
CMAKE_ARGS+=	-DWANT_QT5=ON
CMAKE_ARGS+=	-DWANT_GIG=OFF # requires libgig
CMAKE_ARGS+=	-DWANT_STK=OFF # requires libstk
CMAKE_ARGS+=	-DWANT_CARLA=OFF # requires carla
CMAKE_ARGS+=	-DWANT_SOUNDIO=OFF # requires libsoundio
CMAKE_ARGS+=	-DWANT_SNDIO=OFF # requires sndio
CMAKE_ARGS+=	-DWANT_VST_NOWINE=ON

# for libzynaddsubfx.so in plugins/zynaddsubfx/.
LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/lmms

BUILDLINK_TRANSFORM+=	rm:-floop-optimize2 rm:-fgcse-las

CHECK_PORTABILITY_SKIP+=	cmake/linux/package_linux.sh.in

.include "options.mk"
.include "../../audio/fluidsynth/buildlink3.mk"
.include "../../audio/lame/buildlink3.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../math/fftwf/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}
.include "../../mk/bsd.pkg.mk"
