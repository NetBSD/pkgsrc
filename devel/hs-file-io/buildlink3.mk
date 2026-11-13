# $NetBSD: buildlink3.mk,v 1.6 2026/11/13 14:38:57 pho Exp $

BUILDLINK_TREE+=	hs-file-io

.if !defined(HS_FILE_IO_BUILDLINK3_MK)
HS_FILE_IO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-file-io+=	hs-file-io>=0.2.0
BUILDLINK_ABI_DEPENDS.hs-file-io+=	hs-file-io>=0.2.0nb1
BUILDLINK_PKGSRCDIR.hs-file-io?=	../../devel/hs-file-io

.endif	# HS_FILE_IO_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-file-io
