# $NetBSD: buildlink3.mk,v 1.12 2023/02/07 01:40:47 pho Exp $

BUILDLINK_TREE+=	hs-random

.if !defined(HS_RANDOM_BUILDLINK3_MK)
HS_RANDOM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-random+=	hs-random>=1.2.1
BUILDLINK_ABI_DEPENDS.hs-random+=	hs-random>=1.2.1.1nb1
BUILDLINK_PKGSRCDIR.hs-random?=		../../devel/hs-random

.include "../../devel/hs-splitmix/buildlink3.mk"
.endif	# HS_RANDOM_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-random
