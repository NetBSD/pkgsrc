# $NetBSD: Makefile,v 1.1 2022/04/01 10:43:05 nia Exp $

DISTNAME=	sdl12-compat-1.2.52
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=libsdl-org/}
GITHUB_TAG=	release-${PKGVERSION_NOREV}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://github.com/libsdl-org/sdl12-compat
COMMENT=	SDL-1.2 compatibility layer that uses SDL 2.0 behind the scenes
LICENSE=	zlib

USE_CMAKE=	yes

PKGCONFIG_OVERRIDE+=	sdl12_compat.pc.in

post-install:
	${RM} ${DESTDIR}${PREFIX}/include/SDL/*.orig

.include "../../devel/SDL2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
