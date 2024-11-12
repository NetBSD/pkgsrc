# $NetBSD: Makefile,v 1.1 2024/11/12 21:27:33 nia Exp $

DISTNAME=	furnace-0.6.7
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=tildearrow/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

# don't use pkgsrc fmtlib due to API/ABI stability issues
GITHUB_SUBMODULES+=	fmtlib fmt \
			e57ca2e3685b160617d3d95fcd9e789c4e06ca88 \
			extern/fmt

GITHUB_SUBMODULES+=	superctr adpcm \
			ef7a217154badc3b99978ac481b268c8aab67bd8 \
			extern/adpcm

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tildearrow/furnace
COMMENT=	Multi-system chiptune tracker
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

USE_CXX_FEATURES+=	c++14

CMAKE_CONFIGURE_ARGS+=	-DSYSTEM_FFTW=ON
CMAKE_CONFIGURE_ARGS+=	-DSYSTEM_FREETYPE=ON
CMAKE_CONFIGURE_ARGS+=	-DSYSTEM_LIBSNDFILE=ON
CMAKE_CONFIGURE_ARGS+=	-DSYSTEM_PORTAUDIO=ON
CMAKE_CONFIGURE_ARGS+=	-DSYSTEM_ZLIB=ON
CMAKE_CONFIGURE_ARGS+=	-DSYSTEM_SDL2=ON

CMAKE_CONFIGURE_ARGS+=	-DRTMIDI_API_ALSA=OFF

.include "options.mk"
.include "../../devel/cmake/build.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/portaudio/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
