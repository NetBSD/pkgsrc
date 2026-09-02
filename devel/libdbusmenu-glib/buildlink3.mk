# $NetBSD: buildlink3.mk,v 1.7 2026/09/02 19:01:35 wiz Exp $

BUILDLINK_TREE+=	libdbusmenu-glib

.if !defined(LIBDBUSMENU_GLIB_BUILDLINK3_MK)
LIBDBUSMENU_GLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdbusmenu-glib+=	libdbusmenu-glib>=12.10.2
BUILDLINK_ABI_DEPENDS.libdbusmenu-glib?=	libdbusmenu-glib>=16.04.0nb4
BUILDLINK_PKGSRCDIR.libdbusmenu-glib?=		../../devel/libdbusmenu-glib

.include "../../devel/glib2/buildlink3.mk"
.endif	# LIBDBUSMENU_GLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdbusmenu-glib
