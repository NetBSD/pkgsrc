# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:25:25 joerg Exp $

BUILDLINK_TREE+=	ndesk-dbus

.if !defined(NDESK_DBUS_BUILDLINK3_MK)
NDESK_DBUS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ndesk-dbus+=	ndesk-dbus>=0.6.1a
BUILDLINK_PKGSRCDIR.ndesk-dbus?=	../../sysutils/ndesk-dbus
.endif # NDESK_DBUS_BUILDLINK3_MK

BUILDLINK_TREE+=	-ndesk-dbus
