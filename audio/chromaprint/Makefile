# $NetBSD: Makefile,v 1.16 2016/08/17 00:06:39 ryoon Exp $

DISTNAME=	chromaprint-1.3.2
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	https://bitbucket.org/acoustid/chromaprint/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://acoustid.org/chromaprint
COMMENT=	Audio fingerprinting
LICENSE=	gnu-lgpl-v2

USE_LANGUAGES=	c c++
USE_CMAKE=	yes
# build and install "fpcalc"
CMAKE_ARGS+=	-DBUILD_EXAMPLES:BOOL=on
# tell it where to find ffmpeg
CMAKE_ARGS+=	-DFFMPEG_ROOT:PATH=${BUILDLINK_PREFIX.ffmpeg2}

PKGCONFIG_OVERRIDE=	libchromaprint.pc.cmake

# On Darwin, chromaprint uses Accelerate.framework, but fpcalc still needs FFmpeg
.include "../../multimedia/ffmpeg2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
