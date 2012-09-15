# $NetBSD: buildlink3.mk,v 1.6 2012/09/15 10:06:29 obache Exp $

BUILDLINK_TREE+=	libdevkit-gobject

.if !defined(LIBDEVKIT_GOBJECT_BUILDLINK3_MK)
LIBDEVKIT_GOBJECT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdevkit-gobject+=	libdevkit-gobject>=003
BUILDLINK_ABI_DEPENDS.libdevkit-gobject+=	libdevkit-gobject>=003nb6
BUILDLINK_PKGSRCDIR.libdevkit-gobject?=	../../sysutils/libdevkit-gobject

.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.endif	# LIBDEVKIT_GOBJECT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdevkit-gobject
