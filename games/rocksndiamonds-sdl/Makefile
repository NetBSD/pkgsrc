# $NetBSD: Makefile,v 1.5 2004/10/03 00:14:46 tv Exp $
#

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"

.include "../rocksndiamonds/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-sdl-/}
PKGREVISION=	2
COMMENT=	Game like Boulder Dash, Emerald Mine, or Sokoban (SDL build)

ALL_TARGET=	sdl
CONFLICTS=	rocksndiamonds-[1-9]*

PATCHDIR=	../rocksndiamonds/patches
