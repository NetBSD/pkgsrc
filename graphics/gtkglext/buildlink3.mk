# $NetBSD: buildlink3.mk,v 1.5 2004/10/03 00:14:52 tv Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GTKGLEXT_BUILDLINK3_MK:=	${GTKGLEXT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gtkglext
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngtkglext}
BUILDLINK_PACKAGES+=	gtkglext

.if !empty(GTKGLEXT_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gtkglext+=	gtkglext>=0.7.1nb4
BUILDLINK_RECOMMENDED.gtkglext+=	gtkglext>=0.7.1nb6
BUILDLINK_PKGSRCDIR.gtkglext?=	../../graphics/gtkglext
.endif	# GTKGLEXT_BUILDLINK3_MK

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
