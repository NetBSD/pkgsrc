# $NetBSD: buildlink3.mk,v 1.13 2022/08/20 08:08:21 wiz Exp $

BUILDLINK_TREE+=	hs-mwc-random

.if !defined(HS_MWC_RANDOM_BUILDLINK3_MK)
HS_MWC_RANDOM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-mwc-random+=	hs-mwc-random>=0.15.0
BUILDLINK_ABI_DEPENDS.hs-mwc-random+=	hs-mwc-random>=0.15.0.2nb3
BUILDLINK_PKGSRCDIR.hs-mwc-random?=	../../math/hs-mwc-random

.include "../../math/hs-math-functions/buildlink3.mk"
.include "../../devel/hs-primitive/buildlink3.mk"
.include "../../devel/hs-random/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.endif	# HS_MWC_RANDOM_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-mwc-random
