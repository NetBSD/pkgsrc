# $NetBSD: buildlink3.mk,v 1.2 2022/06/28 11:33:51 wiz Exp $

BUILDLINK_TREE+=	ltfs

.if !defined(LTFS_BUILDLINK3_MK)
LTFS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ltfs+=	ltfs>=2.4.2.0.0
BUILDLINK_ABI_DEPENDS.ltfs+=	ltfs>=2.4.2.0.0nb13
BUILDLINK_PKGSRCDIR.ltfs?=	../../filesystems/ltfs
.endif # LTFS_BUILDLINK3_MK

BUILDLINK_TREE+=	-ltfs
