# $NetBSD: Makefile,v 1.23 2018/01/28 15:43:03 wiz Exp $

DISTNAME=	chromaprint-1.4.3
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
CMAKE_ARGS+=	-DBUILD_TOOLS:BOOL=ON
# tell it where to find ffmpeg
CMAKE_ARGS+=	-DFFMPEG_ROOT:PATH=${BUILDLINK_PREFIX.ffmpeg3}

PKGCONFIG_OVERRIDE=	libchromaprint.pc.cmake

# On Darwin, chromaprint uses Accelerate.framework, but fpcalc still needs FFmpeg
.include "../../multimedia/ffmpeg3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
