# $NetBSD: buildlink3.mk,v 1.1 2023/03/10 21:06:07 ryoon Exp $

BUILDLINK_TREE+=	py-game_sdl2

.if !defined(PY_GAME_SDL2_BUILDLINK3_MK)
PY_GAME_SDL2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py-game_sdl2+=	${PYPKGPREFIX}-game_sdl2>=2.1.0
BUILDLINK_PKGSRCDIR.py-game_sdl2?=	../../devel/py-game_sdl2

BUILDLINK_INCDIRS.py-game_sdl2+=	${PYINC}/pygame_sdl2

.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../fonts/SDL2_ttf/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.endif	# PY_GAME_SDL2_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-game_sdl2
