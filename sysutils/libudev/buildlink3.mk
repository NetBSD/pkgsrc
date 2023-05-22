# $NetBSD: buildlink3.mk,v 1.2 2023/05/22 15:52:56 nikita Exp $

BUILDLINK_TREE+=	libudev

.if !defined(LIBUDEV_BUILDLINK3_MK)
LIBUDEV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libudev+=	libudev>=3.2.12
BUILDLINK_PKGSRCDIR.libudev?=	../../sysutils/libudev
.endif # LIBUDEV_BUILDLINK3_MK

BUILDLINK_TREE+=	-libudev
