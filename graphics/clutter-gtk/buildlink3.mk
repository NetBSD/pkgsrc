# $NetBSD: buildlink3.mk,v 1.48 2024/04/06 08:05:43 wiz Exp $
#

BUILDLINK_TREE+=	clutter-gtk

.if !defined(CLUTTER_GTK_BUILDLINK3_MK)
CLUTTER_GTK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.clutter-gtk+=	clutter-gtk>=1.0
BUILDLINK_ABI_DEPENDS.clutter-gtk+=	clutter-gtk>=1.8.4nb11
BUILDLINK_PKGSRCDIR.clutter-gtk?=	../../graphics/clutter-gtk

.include "../../x11/gtk3/buildlink3.mk"
.include "../../graphics/clutter/buildlink3.mk"
.endif # CLUTTER_GTK_BUILDLINK3_MK

BUILDLINK_TREE+=	-clutter-gtk
