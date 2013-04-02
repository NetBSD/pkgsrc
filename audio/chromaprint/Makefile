# $NetBSD: Makefile,v 1.1 2013/04/02 10:44:41 drochner Exp $
#

DISTNAME=	chromaprint-0.7
CATEGORIES=	audio
MASTER_SITES=	https://bitbucket.org/acoustid/chromaprint/downloads/
FETCH_USING=	curl

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://acoustid.org/chromaprint
COMMENT=	Audio fingerprinting
LICENSE=	gnu-lgpl-v2

#WRKSRC=		${WRKDIR} # More than one possibility -- please check manually.
USE_LANGUAGES=	c c++
USE_CMAKE=	yes
# build and install "fpcalc"
CMAKE_ARGS+=	-DBUILD_EXAMPLES:BOOL=on


.include "../../multimedia/ffmpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
