# $NetBSD: buildlink3.mk,v 1.3 2021/12/08 16:01:56 adam Exp $

BUILDLINK_TREE+=	libdbusmenu-gtk

.if !defined(LIBDBUSMENU_GTK_BUILDLINK3_MK)
LIBDBUSMENU_GTK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdbusmenu-gtk+=	libdbusmenu-gtk>=12.10.2
BUILDLINK_ABI_DEPENDS.libdbusmenu-gtk?=	libdbusmenu-gtk>=12.10.2nb21
BUILDLINK_PKGSRCDIR.libdbusmenu-gtk?=	../../devel/libdbusmenu-gtk

.include "../../devel/libdbusmenu-glib/buildlink3.mk"
.endif	# LIBDBUSMENU_GTK_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdbusmenu-gtk
