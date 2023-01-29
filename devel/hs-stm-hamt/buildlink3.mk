# $NetBSD: buildlink3.mk,v 1.4 2023/01/29 15:50:10 pho Exp $

BUILDLINK_TREE+=	hs-stm-hamt

.if !defined(HS_STM_HAMT_BUILDLINK3_MK)
HS_STM_HAMT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-stm-hamt+=	hs-stm-hamt>=1.2.0
BUILDLINK_ABI_DEPENDS.hs-stm-hamt+=	hs-stm-hamt>=1.2.0.8
BUILDLINK_PKGSRCDIR.hs-stm-hamt?=	../../devel/hs-stm-hamt

.include "../../devel/hs-deferred-folds/buildlink3.mk"
.include "../../devel/hs-focus/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-list-t/buildlink3.mk"
.include "../../devel/hs-primitive/buildlink3.mk"
.include "../../devel/hs-primitive-extras/buildlink3.mk"
.endif	# HS_STM_HAMT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-stm-hamt
