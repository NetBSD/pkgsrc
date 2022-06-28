# $NetBSD: buildlink3.mk,v 1.4 2022/06/28 11:35:56 wiz Exp $

BUILDLINK_TREE+=	hal-info

.if !defined(HAL_INFO_BUILDLINK3_MK)
HAL_INFO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hal-info+=	hal-info>=20081022
BUILDLINK_ABI_DEPENDS.hal-info?=		hal-info>=20091130nb10
BUILDLINK_PKGSRCDIR.hal-info?=		../../sysutils/hal-info
.endif # HAL_INFO_BUILDLINK3_MK

BUILDLINK_TREE+=	-hal-info
