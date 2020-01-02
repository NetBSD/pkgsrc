# $NetBSD: buildlink3.mk,v 1.6 2020/01/02 11:34:29 pho Exp $

BUILDLINK_TREE+=	hs-mwc-random

.if !defined(HS_MWC_RANDOM_BUILDLINK3_MK)
HS_MWC_RANDOM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-mwc-random+=	hs-mwc-random>=0.14.0
BUILDLINK_ABI_DEPENDS.hs-mwc-random+=	hs-mwc-random>=0.14.0.0
BUILDLINK_PKGSRCDIR.hs-mwc-random?=	../../math/hs-mwc-random

.include "../../math/hs-math-functions/buildlink3.mk"
.include "../../devel/hs-primitive/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.endif	# HS_MWC_RANDOM_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-mwc-random
