# $NetBSD: buildlink3.mk,v 1.1.1.1 2005/11/04 07:21:24 rillig Exp $
#
# This Makefile fragment is included by packages that use Coin.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
COIN_BUILDLINK3_MK:=	${COIN_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	Coin
.endif

.if !empty(COIN_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			Coin
BUILDLINK_DEPENDS.Coin+=		Coin>=2.2.1
BUILDLINK_PKGSRCDIR.Coin?=		../../wip/Coin

.include "../../graphics/simage/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"

.endif # COIN_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
