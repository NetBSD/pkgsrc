# $NetBSD: buildlink3.mk,v 1.4 2023/02/07 01:40:59 pho Exp $

BUILDLINK_TREE+=	hs-free

.if !defined(HS_FREE_BUILDLINK3_MK)
HS_FREE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-free+=	hs-free>=5.1.10
BUILDLINK_ABI_DEPENDS.hs-free+=	hs-free>=5.1.10nb1
BUILDLINK_PKGSRCDIR.hs-free?=	../../math/hs-free

.include "../../math/hs-comonad/buildlink3.mk"
.include "../../math/hs-distributive/buildlink3.mk"
.include "../../devel/hs-indexed-traversable/buildlink3.mk"
.include "../../math/hs-semigroupoids/buildlink3.mk"
.include "../../devel/hs-th-abstraction/buildlink3.mk"
.include "../../devel/hs-transformers-base/buildlink3.mk"
.include "../../math/hs-profunctors/buildlink3.mk"
.endif	# HS_FREE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-free
