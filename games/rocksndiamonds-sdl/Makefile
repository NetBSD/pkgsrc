# $NetBSD: Makefile,v 1.8 2005/03/27 15:43:36 wiz Exp $

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../net/SDL_net/buildlink3.mk"

.include "../rocksndiamonds/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-sdl-/}
PKGREVISION=	1
COMMENT=	Game like Boulder Dash, Emerald Mine, or Sokoban (SDL build)

BUILD_TARGET=	sdl
CONFLICTS=	rocksndiamonds-[1-9]*

PATCHDIR=	../rocksndiamonds/patches
