# $NetBSD: buildlink3.mk,v 1.1 2004/02/10 20:58:04 garbled Exp $
#
# This Makefile fragment is included by packages that use gtkglext.
#
# This file was created automatically using createbuildlink-3.0.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GTKGLEXT_BUILDLINK3_MK:=	${GTKGLEXT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gtkglext
.endif

.if !empty(GTKGLEXT_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			gtkglext
BUILDLINK_DEPENDS.gtkglext?=		gtkglext>=0.7.1nb4
BUILDLINK_PKGSRCDIR.gtkglext?=		../../graphics/gtkglext

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.endif # GTKGLEXT_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
