# $NetBSD: buildlink3.mk,v 1.8 2024/05/09 01:32:20 pho Exp $

BUILDLINK_TREE+=	hs-witherable

.if !defined(HS_WITHERABLE_BUILDLINK3_MK)
HS_WITHERABLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-witherable+=	hs-witherable>=0.4.2
BUILDLINK_ABI_DEPENDS.hs-witherable+=	hs-witherable>=0.4.2nb7
BUILDLINK_PKGSRCDIR.hs-witherable?=	../../devel/hs-witherable

.include "../../devel/hs-base-orphans/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-indexed-traversable/buildlink3.mk"
.include "../../devel/hs-indexed-traversable-instances/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.endif	# HS_WITHERABLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-witherable
