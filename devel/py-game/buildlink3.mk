# $NetBSD: buildlink3.mk,v 1.10 2006/07/26 17:56:25 wiz Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
PY_GAME_BUILDLINK3_MK:=	${PY_GAME_BUILDLINK3_MK}+

.include "../../lang/python/pyversion.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	${PYPKGPREFIX}-game
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:N${PYPKGPREFIX}-game}
BUILDLINK_PACKAGES+=	${PYPKGPREFIX}-game
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}${PYPKGPREFIX}-game

.if !empty(PY_GAME_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.${PYPKGPREFIX}-game+=	${PYPKGPREFIX}-game>=1.6
BUILDLINK_ABI_DEPENDS.${PYPKGPREFIX}-game?=	${PYPKGPREFIX}-game>=1.7.1nb4
BUILDLINK_PKGSRCDIR.${PYPKGPREFIX}-game?=	../../devel/py-game

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../multimedia/smpeg/buildlink3.mk"
.include "../../math/py-Numeric/buildlink3.mk"

.endif	# PY_GAME_BUILDLINK3_MK

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
