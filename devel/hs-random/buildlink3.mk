# $NetBSD: buildlink3.mk,v 1.4 2018/01/07 13:04:04 rillig Exp $

BUILDLINK_TREE+=	hs-random

.if !defined(HS_RANDOM_BUILDLINK3_MK)
HS_RANDOM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-random+=	hs-random>=1.1
BUILDLINK_ABI_DEPENDS.hs-random+=	hs-random>=1.1
BUILDLINK_PKGSRCDIR.hs-random?=		../../devel/hs-random
.endif	# HS_RANDOM_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-random
