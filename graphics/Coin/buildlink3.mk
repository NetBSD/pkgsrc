# $NetBSD: buildlink3.mk,v 1.17 2011/11/01 06:01:25 sbd Exp $

BUILDLINK_TREE+=	Coin

.if !defined(COIN_BUILDLINK3_MK)
COIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.Coin+=		Coin>=2.2.1
BUILDLINK_ABI_DEPENDS.Coin+=		Coin>=2.4.4nb8
BUILDLINK_PKGSRCDIR.Coin?=		../../graphics/Coin

.include "../../graphics/simage/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.endif # COIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-Coin
