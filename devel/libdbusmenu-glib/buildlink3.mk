# $NetBSD: buildlink3.mk,v 1.5 2023/11/04 09:15:12 wiz Exp $

BUILDLINK_TREE+=	libdbusmenu-glib

.if !defined(LIBDBUSMENU_GLIB_BUILDLINK3_MK)
LIBDBUSMENU_GLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdbusmenu-glib+=	libdbusmenu-glib>=12.10.2
BUILDLINK_ABI_DEPENDS.libdbusmenu-glib?=	libdbusmenu-glib>=12.10.2nb13
BUILDLINK_PKGSRCDIR.libdbusmenu-glib?=		../../devel/libdbusmenu-glib

.include "../../devel/glib2/buildlink3.mk"
.endif	# LIBDBUSMENU_GLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdbusmenu-glib
