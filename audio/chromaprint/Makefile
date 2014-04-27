# $NetBSD: Makefile,v 1.4 2014/04/27 16:27:09 wiz Exp $

DISTNAME=	chromaprint-1.1
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

.include "../../multimedia/ffmpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
