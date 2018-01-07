# $NetBSD: buildlink3.mk,v 1.7 2018/01/07 13:04:32 rillig Exp $

BUILDLINK_TREE+=	libdevkit-gobject

.if !defined(LIBDEVKIT_GOBJECT_BUILDLINK3_MK)
LIBDEVKIT_GOBJECT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdevkit-gobject+=	libdevkit-gobject>=003
BUILDLINK_ABI_DEPENDS.libdevkit-gobject+=	libdevkit-gobject>=003nb6
BUILDLINK_PKGSRCDIR.libdevkit-gobject?=		../../sysutils/libdevkit-gobject

.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.endif	# LIBDEVKIT_GOBJECT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdevkit-gobject
