# $NetBSD: buildlink3.mk,v 1.20 2006/07/23 01:51:56 minskim Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
CAIRO_BUILDLINK3_MK:=	${CAIRO_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	cairo
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ncairo}
BUILDLINK_PACKAGES+=	cairo
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}cairo

.if !empty(CAIRO_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.0.0nb2
BUILDLINK_ABI_DEPENDS.cairo?=	cairo>=1.0.4nb1
BUILDLINK_PKGSRCDIR.cairo?=	../../graphics/cairo

BUILDLINK_API_DEPENDS.Xrender+=	Xrender>=0.8
.endif	# CAIRO_BUILDLINK3_MK

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glitz/buildlink3.mk"
.include "../../x11/Xrender/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
