# $NetBSD: buildlink3.mk,v 1.68 2026/09/27 11:36:47 tnn Exp $

BUILDLINK_TREE+=	gtkglext

.if !defined(GTKGLEXT_BUILDLINK3_MK)
GTKGLEXT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gtkglext+=	gtkglext>=1.2.0
BUILDLINK_ABI_DEPENDS.gtkglext+=	gtkglext>=1.2.0nb62
BUILDLINK_PKGSRCDIR.gtkglext?=		../../graphics/gtkglext

.include "../../devel/pangox-compat/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif # GTKGLEXT_BUILDLINK3_MK

BUILDLINK_TREE+=	-gtkglext
