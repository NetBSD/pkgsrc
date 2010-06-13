# $NetBSD: buildlink3.mk,v 1.17 2010/06/13 22:44:34 wiz Exp $

BUILDLINK_TREE+=	gtkglext

.if !defined(GTKGLEXT_BUILDLINK3_MK)
GTKGLEXT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gtkglext+=	gtkglext>=1.2.0
BUILDLINK_ABI_DEPENDS.gtkglext?=	gtkglext>=1.2.0nb5
BUILDLINK_PKGSRCDIR.gtkglext?=	../../graphics/gtkglext

.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif # GTKGLEXT_BUILDLINK3_MK

BUILDLINK_TREE+=	-gtkglext
