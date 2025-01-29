# $NetBSD: buildlink3.mk,v 1.17 2025/01/29 16:56:33 pho Exp $

BUILDLINK_TREE+=	hs-random

.if !defined(HS_RANDOM_BUILDLINK3_MK)
HS_RANDOM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-random+=	hs-random>=1.3.0
BUILDLINK_ABI_DEPENDS.hs-random+=	hs-random>=1.3.0
BUILDLINK_PKGSRCDIR.hs-random?=		../../devel/hs-random

.include "../../devel/hs-splitmix/buildlink3.mk"
.endif	# HS_RANDOM_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-random
