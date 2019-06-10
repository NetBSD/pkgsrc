# $NetBSD: Makefile,v 1.52 2019/06/10 19:08:42 nia Exp $
#

VERSION=		1.2.0
PKGNAME=		lmms-${VERSION}
DISTNAME=		lmms_${VERSION}
EXTRACT_SUFX=		.tar.xz
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_GITHUB:=LMMS/}
GITHUB_RELEASE=		v${VERSION}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://lmms.io/
COMMENT=		Cross-platform music production software
LICENSE=		gnu-gpl-v2

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++03
USE_TOOLS+=		gmake perl pkg-config
USE_CMAKE=		yes

WRKSRC=		${WRKDIR}/lmms-${VERSION}

CMAKE_ARGS+=	-DWANT_QT5=ON
CMAKE_ARGS+=	-DWANT_GIG=OFF # requires libgig
CMAKE_ARGS+=	-DWANT_STK=OFF # requires libstk
CMAKE_ARGS+=	-DWANT_CARLA=OFF # requires carla
CMAKE_ARGS+=	-DWANT_SOUNDIO=OFF # requires libsoundio
CMAKE_ARGS+=	-DWANT_VST_NOWINE=ON

BUILDLINK_TRANSFORM+=	rm:-floop-optimize2 rm:-fgcse-las

# for libzynaddsubfx.so in plugins/zynaddsubfx/.
LDFLAGS+=		${COMPILER_RPATH_FLAG}${PREFIX}/lib/lmms

# libSDL defines some symbols that are also defined in libX11, which has
# been fixed in SDL 1.2.11.
BUILDLINK_ABI_DEPENDS.SDL+=	SDL>=1.2.11

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
