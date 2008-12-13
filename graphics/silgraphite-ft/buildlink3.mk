# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/12/13 06:58:01 minskim Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
SILGRAPHITE_FT_BUILDLINK3_MK:=	${SILGRAPHITE_FT_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	silgraphite-ft
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nsilgraphite-ft}
BUILDLINK_PACKAGES+=	silgraphite-ft
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}silgraphite-ft

.if ${SILGRAPHITE_FT_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.silgraphite-ft+=	silgraphite-ft>=2.2.0
BUILDLINK_PKGSRCDIR.silgraphite-ft?=	../../graphics/silgraphite-ft
.endif	# SILGRAPHITE_FT_BUILDLINK3_MK

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/silgraphite/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
