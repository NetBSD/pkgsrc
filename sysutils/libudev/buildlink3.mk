# $NetBSD: buildlink3.mk,v 1.1 2023/05/10 17:39:09 nikita Exp $

BUILDLINK_TREE+=	libudev

.if !defined(LIBUDEV_BUILDLINK3_MK)
LIBUDEV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libudev+=	libudev>=228
BUILDLINK_PKGSRCDIR.libudev?=	../../sysutils/libudev
.endif # LIBUDEV_BUILDLINK3_MK

BUILDLINK_TREE+=	-libudev
