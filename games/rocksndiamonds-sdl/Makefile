# $NetBSD: Makefile,v 1.1.1.1 2003/09/09 15:09:13 adam Exp $
#

PKGNAME=	${DISTNAME:S/-/-sdl-/}

ALL_TARGET=	sdl
CONFLICTS=	rocksndiamonds-[1-9]*

PATCHDIR=	../rocksndiamonds/patches

.include "../../audio/SDL_mixer/buildlink2.mk"
.include "../../graphics/SDL_image/buildlink2.mk"

.include "../rocksndiamonds/Makefile"
