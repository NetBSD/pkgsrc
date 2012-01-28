# $NetBSD: buildlink3.mk,v 1.23 2012/01/28 11:00:52 wiz Exp $

BUILDLINK_TREE+=	${PYPKGPREFIX}-game

.if !defined(PY_GAME_BUILDLINK3_MK)
PY_GAME_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.${PYPKGPREFIX}-game+=	${PYPKGPREFIX}-game>=1.6
BUILDLINK_ABI_DEPENDS.${PYPKGPREFIX}-game?=	${PYPKGPREFIX}-game>=1.8.1nb11
BUILDLINK_PKGSRCDIR.${PYPKGPREFIX}-game?=	../../devel/py-game

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../multimedia/smpeg/buildlink3.mk"
.endif # PY_GAME_BUILDLINK3_MK

BUILDLINK_TREE+=	-${PYPKGPREFIX}-game
