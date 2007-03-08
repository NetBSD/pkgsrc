# $NetBSD: buildlink3.mk,v 1.11 2007/03/08 13:39:20 rillig Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
COIN_BUILDLINK3_MK:=	${COIN_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	Coin
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NCoin}
BUILDLINK_PACKAGES+=	Coin
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}Coin

.if ${COIN_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.Coin+=		Coin>=2.2.1
BUILDLINK_ABI_DEPENDS.Coin+=		Coin>=2.4.4nb3
BUILDLINK_PKGSRCDIR.Coin?=		../../graphics/Coin

.include "../../graphics/simage/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"

.endif # COIN_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
