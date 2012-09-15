# $NetBSD: buildlink3.mk,v 1.19 2012/09/15 10:06:29 obache Exp $

BUILDLINK_TREE+=	libnotify

.if !defined(LIBNOTIFY_BUILDLINK3_MK)
LIBNOTIFY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libnotify+=	libnotify>=0.3.2
BUILDLINK_ABI_DEPENDS.libnotify+=	libnotify>=0.4.5nb11
BUILDLINK_PKGSRCDIR.libnotify?=	../../sysutils/libnotify

.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif # LIBNOTIFY_BUILDLINK3_MK

BUILDLINK_TREE+=	-libnotify
