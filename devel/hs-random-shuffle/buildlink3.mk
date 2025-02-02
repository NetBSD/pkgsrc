# $NetBSD: buildlink3.mk,v 1.7 2025/02/02 13:05:20 pho Exp $

BUILDLINK_TREE+=	hs-random-shuffle

.if !defined(HS_RANDOM_SHUFFLE_BUILDLINK3_MK)
HS_RANDOM_SHUFFLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-random-shuffle+=	hs-random-shuffle>=0.0.4
BUILDLINK_ABI_DEPENDS.hs-random-shuffle+=	hs-random-shuffle>=0.0.4nb6
BUILDLINK_PKGSRCDIR.hs-random-shuffle?=		../../devel/hs-random-shuffle

.include "../../devel/hs-MonadRandom/buildlink3.mk"
.include "../../devel/hs-random/buildlink3.mk"
.endif	# HS_RANDOM_SHUFFLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-random-shuffle
