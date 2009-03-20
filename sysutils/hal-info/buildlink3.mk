# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:25:24 joerg Exp $

BUILDLINK_TREE+=	hal-info

.if !defined(HAL_INFO_BUILDLINK3_MK)
HAL_INFO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hal-info+=	hal-info>=20081022
BUILDLINK_PKGSRCDIR.hal-info?=	../../sysutils/hal-info
.endif # HAL_INFO_BUILDLINK3_MK

BUILDLINK_TREE+=	-hal-info
