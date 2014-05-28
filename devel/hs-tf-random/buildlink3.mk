# $NetBSD: buildlink3.mk,v 1.1 2014/05/28 22:02:11 szptvlfn Exp $

BUILDLINK_TREE+=	hs-tf-random

.if !defined(HS_TF_RANDOM_BUILDLINK3_MK)
HS_TF_RANDOM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-tf-random+=	hs-tf-random>=0.5
BUILDLINK_PKGSRCDIR.hs-tf-random?=	../../devel/hs-tf-random

.include "../../devel/hs-primitive/buildlink3.mk"
.include "../../devel/hs-random/buildlink3.mk"
.endif	# HS_TF_RANDOM_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-tf-random
