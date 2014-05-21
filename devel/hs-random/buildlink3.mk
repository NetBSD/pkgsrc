# $NetBSD: buildlink3.mk,v 1.1 2014/05/21 21:02:18 szptvlfn Exp $

BUILDLINK_TREE+=	hs-random

.if !defined(HS_RANDOM_BUILDLINK3_MK)
HS_RANDOM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-random+=	hs-random>=1.0.1
BUILDLINK_PKGSRCDIR.hs-random?=	../../devel/hs-random
.endif	# HS_RANDOM_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-random
