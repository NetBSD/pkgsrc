# $NetBSD: buildlink3.mk,v 1.4 2023/02/07 01:40:42 pho Exp $

BUILDLINK_TREE+=	hs-lifted-async

.if !defined(HS_LIFTED_ASYNC_BUILDLINK3_MK)
HS_LIFTED_ASYNC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-lifted-async+=	hs-lifted-async>=0.10.2
BUILDLINK_ABI_DEPENDS.hs-lifted-async+=	hs-lifted-async>=0.10.2.3nb1
BUILDLINK_PKGSRCDIR.hs-lifted-async?=	../../devel/hs-lifted-async

.include "../../devel/hs-async/buildlink3.mk"
.include "../../devel/hs-lifted-base/buildlink3.mk"
.include "../../devel/hs-monad-control/buildlink3.mk"
.include "../../devel/hs-transformers-base/buildlink3.mk"
.include "../../devel/hs-constraints/buildlink3.mk"
.endif	# HS_LIFTED_ASYNC_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-lifted-async
