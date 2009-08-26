# $NetBSD: buildlink3.mk,v 1.4 2009/08/26 19:56:57 sno Exp $

BUILDLINK_TREE+=	tomoe-gtk

.if !defined(TOMOE_GTK_BUILDLINK3_MK)
TOMOE_GTK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tomoe-gtk+=	tomoe-gtk>=0.6.0
BUILDLINK_ABI_DEPENDS.tomoe-gtk?=	tomoe-gtk>=0.6.0nb2
BUILDLINK_PKGSRCDIR.tomoe-gtk?=	../../inputmethod/tomoe-gtk

.include "../../inputmethod/tomoe/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif # TOMOE_GTK_BUILDLINK3_MK

BUILDLINK_TREE+=	-tomoe-gtk
