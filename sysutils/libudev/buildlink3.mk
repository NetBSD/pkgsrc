# $NetBSD: buildlink3.mk,v 1.3 2025/05/04 07:18:03 vins Exp $

BUILDLINK_TREE+=	libudev

.if !defined(LIBUDEV_BUILDLINK3_MK)
LIBUDEV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libudev+=	libudev>=3.2.12
BUILDLINK_ABI_DEPENDS.libudev+=	libudev>=3.2.14
BUILDLINK_PKGSRCDIR.libudev?=	../../sysutils/libudev
.endif # LIBUDEV_BUILDLINK3_MK

BUILDLINK_TREE+=	-libudev
