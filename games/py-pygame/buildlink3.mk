# $NetBSD: buildlink3.mk,v 1.1 2013/10/23 11:33:48 ryoon Exp $

BUILDLINK_TREE+=	py27-pygame

.if !defined(PY27_PYGAME_BUILDLINK3_MK)
PY27_PYGAME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py27-pygame+=	py27-pygame>=1.9.1
BUILDLINK_PKGSRCDIR.py27-pygame?=	../../games/py-pygame

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../multimedia/smpeg/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.endif	# PY27_PYGAME_BUILDLINK3_MK

BUILDLINK_TREE+=	-py27-pygame
