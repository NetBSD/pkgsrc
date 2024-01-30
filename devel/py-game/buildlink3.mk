# $NetBSD: buildlink3.mk,v 1.35 2024/01/30 14:21:43 ryoon Exp $

BUILDLINK_TREE+=	py-game

.if !defined(PY_GAME_BUILDLINK3_MK)
PY_GAME_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.py-game+=	${PYPKGPREFIX}-game>=1.9.1
BUILDLINK_ABI_DEPENDS.py-game+=	${PYPKGPREFIX}-game>=2.5.2nb2
BUILDLINK_PKGSRCDIR.py-game?=	../../devel/py-game

.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../fonts/SDL2_ttf/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../multimedia/smpeg/buildlink3.mk"
.if ${OPSYS} != "Darwin"
.  include "../../x11/libX11/buildlink3.mk"
.endif
.endif # PY_GAME_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-game
