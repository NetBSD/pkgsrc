# $NetBSD: buildlink3.mk,v 1.1 2025/12/30 11:25:21 kikadf Exp $

BUILDLINK_TREE+=	libudev-bsd

.if !defined(LIBUDEV_BSD_BUILDLINK3_MK)
LIBUDEV_BSD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libudev-bsd+=	libudev-bsd>=0.6.0.4
BUILDLINK_ABI_DEPENDS.libudev-bsd+=	libudev-bsd>=0.6.0.4
BUILDLINK_PKGSRCDIR.libudev-bsd?=	../../devel/libudev-bsd

.endif # LIBUDEV_BSD_BUILDLINK3_MK

BUILDLINK_TREE+=	-libudev-bsd
