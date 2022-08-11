# $NetBSD: Makefile,v 1.32 2022/08/11 05:08:03 gutteridge Exp $

DISTNAME=	libgroove-4.3.0
PKGREVISION=	13
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=andrewrk/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/andrewrk/libgroove/
COMMENT=	Audio dispatching library
LICENSE=	mit

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
SOEXT=	dylib
.else
SOEXT=	so
.endif

.for lib in AVCODEC AVFILTER AVFORMAT AVUTIL
CMAKE_ARGS+=	-D${lib}_INCLUDE_DIRS=${BUILDLINK_PREFIX.ffmpeg4}/include/ffmpeg4
CMAKE_ARGS+=	-D${lib}_LIBRARIES=${BUILDLINK_PREFIX.ffmpeg4}/lib/ffmpeg4/lib${lib:tl}.${SOEXT}
.endfor

.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
TOOL_DEPENDS+=	yasm-[0-9]*:../../devel/yasm
.endif

BUILDLINK_TRANSFORM+=	rm:-Werror

CFLAGS.NetBSD+=	-D_NETBSD_SOURCE

.include "../../audio/chromaprint/buildlink3.mk"
.include "../../audio/lame/buildlink3.mk"
.include "../../audio/libebur128/buildlink3.mk"
.include "../../audio/speexdsp/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
