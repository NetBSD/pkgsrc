# $NetBSD: buildlink3.mk,v 1.5 2023/11/02 06:36:53 pho Exp $

BUILDLINK_TREE+=	hs-random-shuffle

.if !defined(HS_RANDOM_SHUFFLE_BUILDLINK3_MK)
HS_RANDOM_SHUFFLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-random-shuffle+=	hs-random-shuffle>=0.0.4
BUILDLINK_ABI_DEPENDS.hs-random-shuffle+=	hs-random-shuffle>=0.0.4nb4
BUILDLINK_PKGSRCDIR.hs-random-shuffle?=		../../devel/hs-random-shuffle

.include "../../devel/hs-MonadRandom/buildlink3.mk"
.include "../../devel/hs-random/buildlink3.mk"
.endif	# HS_RANDOM_SHUFFLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-random-shuffle
