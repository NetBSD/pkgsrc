# $NetBSD: buildlink3.mk,v 1.30 2016/08/03 10:22:13 adam Exp $
#

BUILDLINK_TREE+=	clutter-gtk

.if !defined(CLUTTER_GTK_BUILDLINK3_MK)
CLUTTER_GTK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.clutter-gtk+=	clutter-gtk>=1.0
BUILDLINK_ABI_DEPENDS.clutter-gtk+=	clutter-gtk>=1.6.0nb2
BUILDLINK_PKGSRCDIR.clutter-gtk?=	../../graphics/clutter-gtk

.include "../../x11/gtk3/buildlink3.mk"
.include "../../graphics/clutter/buildlink3.mk"
.endif # CLUTTER_GTK_BUILDLINK3_MK

BUILDLINK_TREE+=	-clutter-gtk
