# $NetBSD: buildlink3.mk,v 1.1 2019/02/25 01:00:39 manu Exp $

BUILDLINK_TREE+=	ltfs

.if !defined(LTFS_BUILDLINK3_MK)
LTFS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ltfs+=	ltfs>=2.4.2.0.0
BUILDLINK_ABI_DEPENDS.ltfs+=	ltfs>=2.4.2.0.0
BUILDLINK_PKGSRCDIR.ltfs?=	../../filesystems/ltfs
.endif # LTFS_BUILDLINK3_MK

BUILDLINK_TREE+=	-ltfs
