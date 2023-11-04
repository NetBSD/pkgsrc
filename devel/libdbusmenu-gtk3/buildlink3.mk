# $NetBSD: buildlink3.mk,v 1.4 2023/11/04 09:15:12 wiz Exp $

BUILDLINK_TREE+=	libdbusmenu-gtk3

.if !defined(LIBDBUSMENU_GTK3_BUILDLINK3_MK)
LIBDBUSMENU_GTK3_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdbusmenu-gtk3+=	libdbusmenu-gtk3>=12.10.2
BUILDLINK_ABI_DEPENDS.libdbusmenu-gtk3?=	libdbusmenu-gtk3>=12.10.2nb22
BUILDLINK_PKGSRCDIR.libdbusmenu-gtk3?=		../../devel/libdbusmenu-gtk3

.include "../../devel/libdbusmenu-glib/buildlink3.mk"
.endif	# LIBDBUSMENU_GTK3_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdbusmenu-gtk3
