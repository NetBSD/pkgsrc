# $NetBSD: Makefile,v 1.6 2004/11/03 15:15:08 adam Exp $

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../net/SDL_net/buildlink3.mk"

.include "../rocksndiamonds/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-sdl-/}
COMMENT=	Game like Boulder Dash, Emerald Mine, or Sokoban (SDL build)

ALL_TARGET=	sdl
CONFLICTS=	rocksndiamonds-[1-9]*

PATCHDIR=	../rocksndiamonds/patches
