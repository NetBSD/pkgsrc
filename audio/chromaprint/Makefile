# $NetBSD: Makefile,v 1.44 2025/05/06 07:48:40 wiz Exp $

DISTNAME=	chromaprint-1.5.1
PKGREVISION=	9
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=acoustid/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://acoustid.org/chromaprint
COMMENT=	Audio fingerprinting
LICENSE=	mit

USE_LANGUAGES=	c c++
# build and install "fpcalc"
CMAKE_CONFIGURE_ARGS+=	-DBUILD_TOOLS=ON
CMAKE_CONFIGURE_ARGS+=	-DFFT_LIB=fftw3

USE_CXX_FEATURES+=	c++11

.for lib in AVCODEC AVFORMAT AVUTIL SWRESAMPLE
CMAKE_CONFIGURE_ARGS+=	-DFFMPEG_LIB${lib}_INCLUDE_DIRS=${BUILDLINK_PREFIX.ffmpeg7}/include/ffmpeg7
CMAKE_CONFIGURE_ARGS+=	-DFFMPEG_LIB${lib}_LIBRARIES=${BUILDLINK_PREFIX.ffmpeg7}/lib/ffmpeg7/lib${lib:tl}.${SHLIB_EXT}
.endfor

PKGCONFIG_OVERRIDE=	libchromaprint.pc.cmake

.include "options.mk"
.include "../../devel/cmake/build.mk"
.include "../../math/fftw/buildlink3.mk"
# On Darwin, chromaprint uses Accelerate.framework, but fpcalc still needs FFmpeg
.include "../../multimedia/ffmpeg7/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
