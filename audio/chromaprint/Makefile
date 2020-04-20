# $NetBSD: Makefile,v 1.28 2020/04/20 06:55:19 wiz Exp $

DISTNAME=	chromaprint-1.5.0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=acoustid/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://acoustid.org/chromaprint
COMMENT=	Audio fingerprinting
LICENSE=	mit

USE_LANGUAGES=	c c++
USE_CMAKE=	yes
# build and install "fpcalc"
CMAKE_ARGS+=	-DBUILD_TOOLS=ON
CMAKE_ARGS+=	-DFFT_LIB=fftw3

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
SOEXT=	dylib
.else
SOEXT=	so
.endif

.for lib in AVCODEC AVFORMAT AVUTIL SWRESAMPLE
CMAKE_ARGS+=	-DFFMPEG_LIB${lib}_INCLUDE_DIRS=${BUILDLINK_PREFIX.ffmpeg4}/include/ffmpeg4
CMAKE_ARGS+=	-DFFMPEG_LIB${lib}_LIBRARIES=${BUILDLINK_PREFIX.ffmpeg4}/lib/ffmpeg4/lib${lib:tl}.${SOEXT}
.endfor

PKGCONFIG_OVERRIDE=	libchromaprint.pc.cmake

.include "../../math/fftw/buildlink3.mk"
# On Darwin, chromaprint uses Accelerate.framework, but fpcalc still needs FFmpeg
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
