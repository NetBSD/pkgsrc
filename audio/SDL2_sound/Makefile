# $NetBSD: Makefile,v 1.2 2022/10/04 07:54:28 wiz Exp $

DISTNAME=	SDL_sound-2.0.1
PKGNAME=	${DISTNAME:S/SDL/SDL2/}
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=icculus/}
GITHUB_PROJECT=	SDL_sound
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://icculus.org/SDL_sound/
COMMENT=	SDL2 library to handle the decoding of different sound formats
LICENSE=	zlib

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

# dont't build and install playsound
# to not conflict with audio/SDL_sound
CMAKE_ARGS+=	-DSDLSOUND_BUILD_TEST:BOOL=FALSE

.include "../../devel/SDL2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
