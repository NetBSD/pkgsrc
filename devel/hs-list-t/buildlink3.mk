# $NetBSD: buildlink3.mk,v 1.3 2022/08/20 08:08:17 wiz Exp $

BUILDLINK_TREE+=	hs-list-t

.if !defined(HS_LIST_T_BUILDLINK3_MK)
HS_LIST_T_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-list-t+=	hs-list-t>=1.0.5
BUILDLINK_ABI_DEPENDS.hs-list-t+=	hs-list-t>=1.0.5.1nb2
BUILDLINK_PKGSRCDIR.hs-list-t?=		../../devel/hs-list-t

.include "../../devel/hs-foldl/buildlink3.mk"
.include "../../devel/hs-logict/buildlink3.mk"
.include "../../devel/hs-mmorph/buildlink3.mk"
.include "../../devel/hs-monad-control/buildlink3.mk"
.include "../../math/hs-semigroups/buildlink3.mk"
.include "../../devel/hs-transformers-base/buildlink3.mk"
.endif	# HS_LIST_T_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-list-t
