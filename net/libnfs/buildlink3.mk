# $NetBSD: buildlink3.mk,v 1.1 2026/05/01 19:43:30 vins Exp $

BUILDLINK_TREE+=	libnfs

.if !defined(LIBNFS_BUILDLINK3_MK)
LIBNFS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libnfs+=	libnfs>=6.0.2
BUILDLINK_PKGSRCDIR.libnfs?=	../../net/libnfs
.endif	# LIBNFS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libnfs
