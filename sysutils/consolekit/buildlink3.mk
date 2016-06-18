# $NetBSD: buildlink3.mk,v 1.8 2016/06/18 10:23:16 youri Exp $

BUILDLINK_TREE+=	consolekit

.if !defined(CONSOLEKIT_BUILDLINK3_MK)
CONSOLEKIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.consolekit+=	consolekit>=1.0.2
BUILDLINK_ABI_DEPENDS.consolekit+=	consolekit>=1.0.2
BUILDLINK_PKGSRCDIR.consolekit?=	../../sysutils/consolekit

.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.endif # CONSOLEKIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-consolekit
