# $NetBSD: buildlink3.mk,v 1.1 2016/05/20 22:01:11 youri Exp $

BUILDLINK_TREE+=	libdbusmenu-gtk

.if !defined(LIBDBUSMENU_GTK_BUILDLINK3_MK)
LIBDBUSMENU_GTK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdbusmenu-gtk+=	libdbusmenu-gtk>=12.10.2
BUILDLINK_PKGSRCDIR.libdbusmenu-gtk?=	../../devel/libdbusmenu-gtk

.include "../../devel/libdbusmenu-glib/buildlink3.mk"
.endif	# LIBDBUSMENU_GTK_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdbusmenu-gtk
