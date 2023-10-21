# $NetBSD: buildlink3.mk,v 1.12 2023/10/21 17:10:32 gdt Exp $

BUILDLINK_TREE+=	imlib-gtk

.if !defined(IMLIB_GTK_BUILDLINK3_MK)
IMLIB_GTK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.imlib-gtk+=	imlib-gtk>=1.9.15
BUILDLINK_ABI_DEPENDS.imlib-gtk+=	imlib-gtk>=1.9.15nb11
BUILDLINK_PKGSRCDIR.imlib-gtk?=		../../graphics/imlib-gtk

.include "../../graphics/imlib/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.endif	# IMLIB_GTK_BUILDLINK3_MK

BUILDLINK_TREE+=	-imlib-gtk
