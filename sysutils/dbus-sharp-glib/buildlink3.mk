# $NetBSD: buildlink3.mk,v 1.6 2016/04/11 19:01:38 ryoon Exp $

BUILDLINK_TREE+=	dbus-sharp-glib

.if !defined(DBUS_SHARP_GLIB_BUILDLINK3_MK)
DBUS_SHARP_GLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.dbus-sharp-glib+=	dbus-sharp-glib>=0.5.0
BUILDLINK_ABI_DEPENDS.dbus-sharp-glib?=	dbus-sharp-glib>=0.5.0nb7
BUILDLINK_PKGSRCDIR.dbus-sharp-glib?=	../../sysutils/dbus-sharp-glib

.include "../../sysutils/dbus-sharp/buildlink3.mk"
.endif	# DBUS_SHARP_GLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-dbus-sharp-glib
