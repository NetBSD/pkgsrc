# $NetBSD: buildlink3.mk,v 1.1 2014/05/19 12:22:06 adam Exp $

BUILDLINK_TREE+=	libntfs

.if !defined(LIBNTFS_BUILDLINK3_MK)
LIBNTFS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libntfs+=	libntfs>=2014.2.15
BUILDLINK_PKGSRCDIR.libntfs?=	../../filesystems/libntfs
.endif	# LIBNTFS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libntfs
