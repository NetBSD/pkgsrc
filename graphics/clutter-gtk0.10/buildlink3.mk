# $NetBSD: buildlink3.mk,v 1.15 2020/03/10 22:08:48 wiz Exp $
#

BUILDLINK_TREE+=	clutter-gtk0.10

.if !defined(CLUTTER_GTK0.10_BUILDLINK3_MK)
CLUTTER_GTK0.10_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.clutter-gtk0.10+=	clutter-gtk0.10>=0.10.0
BUILDLINK_ABI_DEPENDS.clutter-gtk0.10?=	clutter-gtk0.10>=0.10.8nb13
BUILDLINK_PKGSRCDIR.clutter-gtk0.10?=	../../graphics/clutter-gtk0.10

.include "../../x11/gtk2/buildlink3.mk"
.include "../../graphics/clutter/buildlink3.mk"
.endif # CLUTTER_GTK0.10_BUILDLINK3_MK

BUILDLINK_TREE+=	-clutter-gtk0.10
