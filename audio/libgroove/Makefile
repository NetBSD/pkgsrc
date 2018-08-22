# $NetBSD: Makefile,v 1.21 2018/08/22 09:42:55 wiz Exp $

DISTNAME=	libgroove-4.3.0
PKGREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=andrewrk/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/andrewrk/libgroove/
COMMENT=	Audio dispatching library
LICENSE=	mit

USE_CMAKE=	yes
USE_TOOLS+=	gmake pkg-config perl:build
USE_LANGUAGES=	c c++

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
SOEXT=	dylib
.else
SOEXT=	so
.endif

CMAKE_ARGS+=	-DAVFILTER_INCLUDE_DIRS:PATH=${BUILDLINK_PREFIX.ffmpeg3}/include/ffmpeg3
CMAKE_ARGS+=	-DAVFILTER_LIBRARIES:PATH=${BUILDLINK_PREFIX.ffmpeg3}/lib/ffmpeg3/libavfilter.${SOEXT}

CMAKE_ARGS+=	-DAVFORMAT_INCLUDE_DIRS:PATH=${BUILDLINK_PREFIX.ffmpeg3}/include/ffmpeg3
CMAKE_ARGS+=	-DAVFORMAT_LIBRARIES:PATH=${BUILDLINK_PREFIX.ffmpeg3}/lib/ffmpeg3/libavformat.${SOEXT}

CMAKE_ARGS+=	-DAVCODEC_INCLUDE_DIRS:PATH=${BUILDLINK_PREFIX.ffmpeg3}/include/ffmpeg3
CMAKE_ARGS+=	-DAVCODEC_LIBRARIES:PATH=${BUILDLINK_PREFIX.ffmpeg3}/lib/ffmpeg3/libavcodec.${SOEXT}

CMAKE_ARGS+=	-DAVUTIL_INCLUDE_DIRS:PATH=${BUILDLINK_PREFIX.ffmpeg3}/include/ffmpeg3
CMAKE_ARGS+=	-DAVUTIL_LIBRARIES:PATH=${BUILDLINK_PREFIX.ffmpeg3}/lib/ffmpeg3/libavutil.${SOEXT}

.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
BUILD_DEPENDS+=	yasm-[0-9]*:../../devel/yasm
.endif

BUILDLINK_TRANSFORM+=	rm:-Werror

CFLAGS.NetBSD+=	-D_NETBSD_SOURCE

.include "../../audio/chromaprint/buildlink3.mk"
.include "../../audio/lame/buildlink3.mk"
.include "../../audio/libebur128/buildlink3.mk"
.include "../../audio/speexdsp/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../multimedia/ffmpeg3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
