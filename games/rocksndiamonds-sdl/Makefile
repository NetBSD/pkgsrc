# $NetBSD: Makefile,v 1.3 2004/01/03 18:49:41 reed Exp $
#

.include "../../audio/SDL_mixer/buildlink2.mk"
.include "../../graphics/SDL_image/buildlink2.mk"

.include "../rocksndiamonds/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-sdl-/}
PKGREVISION=	1
COMMENT=	Game like Boulder Dash, Emerald Mine, or Sokoban (SDL build)

ALL_TARGET=	sdl
CONFLICTS=	rocksndiamonds-[1-9]*

PATCHDIR=	../rocksndiamonds/patches
