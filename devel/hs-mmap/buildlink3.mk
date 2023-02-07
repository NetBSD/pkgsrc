# $NetBSD: buildlink3.mk,v 1.5 2023/02/07 01:40:44 pho Exp $

BUILDLINK_TREE+=	hs-mmap

.if !defined(HS_MMAP_BUILDLINK3_MK)
HS_MMAP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-mmap+=	hs-mmap>=0.5.9
BUILDLINK_ABI_DEPENDS.hs-mmap+=	hs-mmap>=0.5.9nb4
BUILDLINK_PKGSRCDIR.hs-mmap?=	../../devel/hs-mmap
.endif	# HS_MMAP_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-mmap
