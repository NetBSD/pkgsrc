# $NetBSD: buildlink3.mk,v 1.26 2026/09/02 19:04:28 wiz Exp $

BUILDLINK_TREE+=	gnome-menus

.if !defined(GNOME_MENUS_BUILDLINK3_MK)
GNOME_MENUS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnome-menus+=	gnome-menus>=2.13.5
BUILDLINK_ABI_DEPENDS.gnome-menus+=	gnome-menus>=2.30.5nb9
BUILDLINK_PKGSRCDIR.gnome-menus?=	../../sysutils/gnome-menus

.include "../../devel/glib2/buildlink3.mk"
.endif # GNOME_MENUS_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnome-menus
