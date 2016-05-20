# $NetBSD: buildlink3.mk,v 1.1 2016/05/20 22:00:23 youri Exp $

BUILDLINK_TREE+=	libdbusmenu-glib

.if !defined(LIBDBUSMENU_GLIB_BUILDLINK3_MK)
LIBDBUSMENU_GLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdbusmenu-glib+=libdbusmenu-glib>=12.10.2
BUILDLINK_PKGSRCDIR.libdbusmenu-glib?=	../../devel/libdbusmenu-glib

.include "../../devel/glib2/buildlink3.mk"
.endif	# LIBDBUSMENU_GLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdbusmenu-glib
