# $NetBSD: buildlink3.mk,v 1.46 2026/01/07 08:48:50 wiz Exp $

BUILDLINK_TREE+=	edbus

.if !defined(EDBUS_BUILDLINK3_MK)
EDBUS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.edbus+=	edbus>=1.7.10
BUILDLINK_ABI_DEPENDS.edbus?=	edbus>=1.7.10nb22
BUILDLINK_PKGSRCDIR.edbus?=	../../sysutils/edbus

.include "../../devel/ecore/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/efreet/buildlink3.mk"
.endif # EDBUS_BUILDLINK3_MK

BUILDLINK_TREE+=	-edbus
