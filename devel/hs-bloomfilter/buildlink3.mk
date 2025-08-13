# $NetBSD: buildlink3.mk,v 1.6 2025/08/13 11:06:32 pho Exp $

BUILDLINK_TREE+=	hs-bloomfilter

.if !defined(HS_BLOOMFILTER_BUILDLINK3_MK)
HS_BLOOMFILTER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-bloomfilter+=	hs-bloomfilter>=2.0.1
BUILDLINK_ABI_DEPENDS.hs-bloomfilter+=	hs-bloomfilter>=2.0.1.2nb5
BUILDLINK_PKGSRCDIR.hs-bloomfilter?=	../../devel/hs-bloomfilter
.endif	# HS_BLOOMFILTER_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-bloomfilter
