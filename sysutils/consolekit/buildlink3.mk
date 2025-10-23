# $NetBSD: buildlink3.mk,v 1.14 2025/10/23 20:39:16 wiz Exp $

BUILDLINK_TREE+=	consolekit

.if !defined(CONSOLEKIT_BUILDLINK3_MK)
CONSOLEKIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.consolekit+=	consolekit>=0.3.0
BUILDLINK_ABI_DEPENDS.consolekit+=	consolekit>=1.2.6nb1
BUILDLINK_PKGSRCDIR.consolekit?=	../../sysutils/consolekit

.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.endif # CONSOLEKIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-consolekit
