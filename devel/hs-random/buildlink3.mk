# $NetBSD: buildlink3.mk,v 1.20 2025/08/13 11:06:54 pho Exp $

BUILDLINK_TREE+=	hs-random

.if !defined(HS_RANDOM_BUILDLINK3_MK)
HS_RANDOM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-random+=	hs-random>=1.3.0
BUILDLINK_ABI_DEPENDS.hs-random+=	hs-random>=1.3.0nb3
BUILDLINK_PKGSRCDIR.hs-random?=		../../devel/hs-random

.include "../../devel/hs-splitmix/buildlink3.mk"
.endif	# HS_RANDOM_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-random
