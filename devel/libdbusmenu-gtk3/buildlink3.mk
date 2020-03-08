# $NetBSD: buildlink3.mk,v 1.2 2020/03/08 16:47:36 wiz Exp $

BUILDLINK_TREE+=	libdbusmenu-gtk3

.if !defined(LIBDBUSMENU_GTK3_BUILDLINK3_MK)
LIBDBUSMENU_GTK3_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdbusmenu-gtk3+=	libdbusmenu-gtk3>=12.10.2
BUILDLINK_ABI_DEPENDS.libdbusmenu-gtk3?=		libdbusmenu-gtk3>=12.10.2nb16
BUILDLINK_PKGSRCDIR.libdbusmenu-gtk3?=		../../devel/libdbusmenu-gtk3

.include "../../devel/libdbusmenu-glib/buildlink3.mk"
.endif	# LIBDBUSMENU_GTK3_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdbusmenu-gtk3
