# $NetBSD: buildlink3.mk,v 1.7 2025/02/02 13:05:17 pho Exp $

BUILDLINK_TREE+=	hs-parallel

.if !defined(HS_PARALLEL_BUILDLINK3_MK)
HS_PARALLEL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-parallel+=	hs-parallel>=3.2.2
BUILDLINK_ABI_DEPENDS.hs-parallel+=	hs-parallel>=3.2.2.0nb6
BUILDLINK_PKGSRCDIR.hs-parallel?=	../../devel/hs-parallel
.endif	# HS_PARALLEL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-parallel
