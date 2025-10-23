# $NetBSD: buildlink3.mk,v 1.10 2025/10/23 20:39:22 wiz Exp $

BUILDLINK_TREE+=	libdevkit-gobject

.if !defined(LIBDEVKIT_GOBJECT_BUILDLINK3_MK)
LIBDEVKIT_GOBJECT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdevkit-gobject+=	libdevkit-gobject>=003
BUILDLINK_ABI_DEPENDS.libdevkit-gobject+=	libdevkit-gobject>=003nb22
BUILDLINK_PKGSRCDIR.libdevkit-gobject?=		../../sysutils/libdevkit-gobject

.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.endif	# LIBDEVKIT_GOBJECT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdevkit-gobject
