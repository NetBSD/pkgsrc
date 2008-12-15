# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/12/15 00:44:52 minskim Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
SILGRAPHITE_XFT_BUILDLINK3_MK:=	${SILGRAPHITE_XFT_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	silgraphite-xft
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nsilgraphite-xft}
BUILDLINK_PACKAGES+=	silgraphite-xft
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}silgraphite-xft

.if ${SILGRAPHITE_XFT_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.silgraphite-xft+=	silgraphite-xft>=2.3
BUILDLINK_PKGSRCDIR.silgraphite-xft?=	../../wip/silgraphite-xft
.endif	# SILGRAPHITE_XFT_BUILDLINK3_MK

.include "../../graphics/silgraphite-ft/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
