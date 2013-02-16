# $NetBSD: buildlink3.mk,v 1.18 2013/02/16 11:18:19 wiz Exp $
#

BUILDLINK_TREE+=	clutter-gtk

.if !defined(CLUTTER_GTK_BUILDLINK3_MK)
CLUTTER_GTK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.clutter-gtk+=	clutter-gtk>=0.10.0
BUILDLINK_ABI_DEPENDS.clutter-gtk+=	clutter-gtk>=0.10.8nb11
BUILDLINK_PKGSRCDIR.clutter-gtk?=	../../graphics/clutter-gtk

.include "../../x11/gtk2/buildlink3.mk"
.include "../../graphics/clutter/buildlink3.mk"
.endif # CLUTTER_GTK_BUILDLINK3_MK

BUILDLINK_TREE+=	-clutter-gtk
