# $NetBSD: buildlink3.mk,v 1.9 2024/05/09 01:31:52 pho Exp $

BUILDLINK_TREE+=	hs-deferred-folds

.if !defined(HS_DEFERRED_FOLDS_BUILDLINK3_MK)
HS_DEFERRED_FOLDS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-deferred-folds+=	hs-deferred-folds>=0.9.18
BUILDLINK_ABI_DEPENDS.hs-deferred-folds+=	hs-deferred-folds>=0.9.18.6nb1
BUILDLINK_PKGSRCDIR.hs-deferred-folds?=		../../devel/hs-deferred-folds

.include "../../devel/hs-foldl/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-primitive/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.endif	# HS_DEFERRED_FOLDS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-deferred-folds
