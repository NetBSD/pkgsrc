# $NetBSD: Makefile,v 1.6 2024/01/30 14:21:29 ryoon Exp $

DISTNAME=	SDL2_sound-2.0.2
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=icculus/}
GITHUB_PROJECT=	SDL_sound
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/icculus/SDL_sound
COMMENT=	SDL2 library to handle the decoding of different sound formats
LICENSE=	zlib

USE_LANGUAGES=	c c++

# dont't build and install playsound
# to not conflict with audio/SDL_sound
CMAKE_CONFIGURE_ARGS+=	-DSDLSOUND_BUILD_TEST=NO

.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
