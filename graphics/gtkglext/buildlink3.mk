# $NetBSD: buildlink3.mk,v 1.3 2004/03/16 17:58:01 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GTKGLEXT_BUILDLINK3_MK:=	${GTKGLEXT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gtkglext
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngtkglext}
BUILDLINK_PACKAGES+=	gtkglext

.if !empty(GTKGLEXT_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gtkglext+=	gtkglext>=0.7.1nb4
BUILDLINK_PKGSRCDIR.gtkglext?=	../../graphics/gtkglext

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.endif	# GTKGLEXT_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
