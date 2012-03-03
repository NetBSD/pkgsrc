# $NetBSD: buildlink3.mk,v 1.5 2012/03/03 00:12:20 wiz Exp $

BUILDLINK_TREE+=	hal

.if !defined(HAL_BUILDLINK3_MK)
HAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hal+=	hal>=0.5.11
BUILDLINK_ABI_DEPENDS.hal?=	hal>=0.5.14nb5
BUILDLINK_PKGSRCDIR.hal?=	../../sysutils/hal

.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.endif # HAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hal
