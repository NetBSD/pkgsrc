# $NetBSD: buildlink3.mk,v 1.6 2022/01/18 02:48:09 pho Exp $

BUILDLINK_TREE+=	hs-lifted-base

.if !defined(HS_LIFTED_BASE_BUILDLINK3_MK)
HS_LIFTED_BASE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-lifted-base+=	hs-lifted-base>=0.2.3
BUILDLINK_ABI_DEPENDS.hs-lifted-base+=	hs-lifted-base>=0.2.3.12nb2
BUILDLINK_PKGSRCDIR.hs-lifted-base?=	../../devel/hs-lifted-base

.include "../../devel/hs-monad-control/buildlink3.mk"
.include "../../devel/hs-transformers-base/buildlink3.mk"
.endif	# HS_LIFTED_BASE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-lifted-base
