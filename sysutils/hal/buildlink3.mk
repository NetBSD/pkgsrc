# $NetBSD: buildlink3.mk,v 1.10 2022/06/28 11:35:56 wiz Exp $

BUILDLINK_TREE+=	hal

.if !defined(HAL_BUILDLINK3_MK)
HAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hal+=	hal>=0.5.11
BUILDLINK_ABI_DEPENDS.hal+=	hal>=0.5.14nb30
BUILDLINK_PKGSRCDIR.hal?=	../../sysutils/hal

.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.endif # HAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hal
