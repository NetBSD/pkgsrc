# $NetBSD: buildlink3.mk,v 1.1 2013/05/04 12:17:04 dsainty Exp $

BUILDLINK_TREE+=	fuse-ntfs-3g

.if !defined(FUSE_NTFS_3G_BUILDLINK3_MK)
FUSE_NTFS_3G_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fuse-ntfs-3g+=	fuse-ntfs-3g>=1.1120
BUILDLINK_PKGSRCDIR.fuse-ntfs-3g?=	../../filesystems/fuse-ntfs-3g
.endif	# FUSE_NTFS_3G_BUILDLINK3_MK

BUILDLINK_TREE+=	-fuse-ntfs-3g
