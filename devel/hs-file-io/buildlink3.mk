# $NetBSD: buildlink3.mk,v 1.3 2025/03/05 03:39:11 pho Exp $

BUILDLINK_TREE+=	hs-file-io

.if !defined(HS_FILE_IO_BUILDLINK3_MK)
HS_FILE_IO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-file-io+=	hs-file-io>=0.1.5
BUILDLINK_ABI_DEPENDS.hs-file-io+=	hs-file-io>=0.1.5nb2
BUILDLINK_PKGSRCDIR.hs-file-io?=	../../devel/hs-file-io

.endif	# HS_FILE_IO_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-file-io
