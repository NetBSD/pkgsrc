# $NetBSD: Makefile,v 1.2 2003/09/15 15:21:46 adam Exp $
#

.include "../../audio/SDL_mixer/buildlink2.mk"
.include "../../graphics/SDL_image/buildlink2.mk"

.include "../rocksndiamonds/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-sdl-/}
COMMENT=	Game like Boulder Dash, Emerald Mine, or Sokoban (SDL build)

ALL_TARGET=	sdl
CONFLICTS=	rocksndiamonds-[1-9]*

PATCHDIR=	../rocksndiamonds/patches
