# $NetBSD: buildlink3.mk,v 1.8 2024/05/09 01:32:25 pho Exp $

BUILDLINK_TREE+=	hs-free

.if !defined(HS_FREE_BUILDLINK3_MK)
HS_FREE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-free+=	hs-free>=5.2
BUILDLINK_ABI_DEPENDS.hs-free+=	hs-free>=5.2nb2
BUILDLINK_PKGSRCDIR.hs-free?=	../../math/hs-free

.include "../../math/hs-comonad/buildlink3.mk"
.include "../../math/hs-distributive/buildlink3.mk"
.include "../../devel/hs-indexed-traversable/buildlink3.mk"
.include "../../math/hs-profunctors/buildlink3.mk"
.include "../../math/hs-semigroupoids/buildlink3.mk"
.include "../../devel/hs-th-abstraction/buildlink3.mk"
.include "../../devel/hs-transformers-base/buildlink3.mk"
.endif	# HS_FREE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-free
