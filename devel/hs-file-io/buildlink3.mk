# $NetBSD: buildlink3.mk,v 1.4 2025/08/13 11:06:39 pho Exp $

BUILDLINK_TREE+=	hs-file-io

.if !defined(HS_FILE_IO_BUILDLINK3_MK)
HS_FILE_IO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-file-io+=	hs-file-io>=0.1.5
BUILDLINK_ABI_DEPENDS.hs-file-io+=	hs-file-io>=0.1.5nb3
BUILDLINK_PKGSRCDIR.hs-file-io?=	../../devel/hs-file-io

.endif	# HS_FILE_IO_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-file-io
