# $NetBSD: buildlink3.mk,v 1.15 2013/12/13 14:51:23 ryoon Exp $

BUILDLINK_TREE+=	dbus

.if !defined(DBUS_BUILDLINK3_MK)
DBUS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.dbus+=	dbus>=0.91
BUILDLINK_PKGSRCDIR.dbus?=	../../sysutils/dbus

BUILDLINK_INCDIRS.dbus+=	lib/dbus-1.0/include/dbus
BUILDLINK_FNAME_TRANSFORM.dbus+=	-e "s|lib/dbus-1.0/||"

.include "../../textproc/expat/buildlink3.mk"
.endif # DBUS_BUILDLINK3_MK

BUILDLINK_TREE+=	-dbus
