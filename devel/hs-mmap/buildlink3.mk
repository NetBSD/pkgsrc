# $NetBSD: buildlink3.mk,v 1.12 2026/11/13 14:39:08 pho Exp $

BUILDLINK_TREE+=	hs-mmap

.if !defined(HS_MMAP_BUILDLINK3_MK)
HS_MMAP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-mmap+=	hs-mmap>=0.5.9
BUILDLINK_ABI_DEPENDS.hs-mmap+=	hs-mmap>=0.5.9nb11
BUILDLINK_PKGSRCDIR.hs-mmap?=	../../devel/hs-mmap
.endif	# HS_MMAP_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-mmap
