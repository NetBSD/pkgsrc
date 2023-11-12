# $NetBSD: Makefile,v 1.39 2023/11/12 13:20:35 wiz Exp $

DISTNAME=	chromaprint-1.5.1
PKGREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=acoustid/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://acoustid.org/chromaprint
COMMENT=	Audio fingerprinting
LICENSE=	mit

USE_LANGUAGES=	c c++
# build and install "fpcalc"
CMAKE_ARGS+=	-DBUILD_TOOLS=ON
CMAKE_ARGS+=	-DFFT_LIB=fftw3

USE_CXX_FEATURES+=	c++11

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
SOEXT=	dylib
.else
SOEXT=	so
.endif

.for lib in AVCODEC AVFORMAT AVUTIL SWRESAMPLE
CMAKE_ARGS+=	-DFFMPEG_LIB${lib}_INCLUDE_DIRS=${BUILDLINK_PREFIX.ffmpeg6}/include/ffmpeg6
CMAKE_ARGS+=	-DFFMPEG_LIB${lib}_LIBRARIES=${BUILDLINK_PREFIX.ffmpeg6}/lib/ffmpeg6/lib${lib:tl}.${SOEXT}
.endfor

PKGCONFIG_OVERRIDE=	libchromaprint.pc.cmake

.include "options.mk"
.include "../../devel/cmake/build.mk"
.include "../../math/fftw/buildlink3.mk"
# On Darwin, chromaprint uses Accelerate.framework, but fpcalc still needs FFmpeg
.include "../../multimedia/ffmpeg6/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
