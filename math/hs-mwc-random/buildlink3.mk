# $NetBSD: buildlink3.mk,v 1.16 2023/11/02 06:37:13 pho Exp $

BUILDLINK_TREE+=	hs-mwc-random

.if !defined(HS_MWC_RANDOM_BUILDLINK3_MK)
HS_MWC_RANDOM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-mwc-random+=	hs-mwc-random>=0.15.0
BUILDLINK_ABI_DEPENDS.hs-mwc-random+=	hs-mwc-random>=0.15.0.2nb6
BUILDLINK_PKGSRCDIR.hs-mwc-random?=	../../math/hs-mwc-random

.include "../../math/hs-math-functions/buildlink3.mk"
.include "../../devel/hs-primitive/buildlink3.mk"
.include "../../devel/hs-random/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.endif	# HS_MWC_RANDOM_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-mwc-random
