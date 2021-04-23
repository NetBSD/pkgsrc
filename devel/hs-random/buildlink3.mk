# $NetBSD: buildlink3.mk,v 1.5 2021/04/23 06:51:27 pho Exp $

BUILDLINK_TREE+=	hs-random

.if !defined(HS_RANDOM_BUILDLINK3_MK)
HS_RANDOM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-random+=	hs-random>=1.2.0
BUILDLINK_ABI_DEPENDS.hs-random+=	hs-random>=1.2.0
BUILDLINK_PKGSRCDIR.hs-random?=		../../devel/hs-random
.endif	# HS_RANDOM_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-random
