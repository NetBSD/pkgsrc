# $NetBSD: buildlink3.mk,v 1.5 2023/02/07 01:40:58 pho Exp $

BUILDLINK_TREE+=	hs-purescript-cst

.if !defined(HS_PURESCRIPT_CST_BUILDLINK3_MK)
HS_PURESCRIPT_CST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-purescript-cst+=	hs-purescript-cst>=0.4.0
BUILDLINK_ABI_DEPENDS.hs-purescript-cst+=	hs-purescript-cst>=0.5.0.0nb2
BUILDLINK_PKGSRCDIR.hs-purescript-cst?=		../../lang/hs-purescript-cst

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-base-compat/buildlink3.mk"
.include "../../devel/hs-dlist/buildlink3.mk"
.include "../../devel/hs-microlens/buildlink3.mk"
.include "../../devel/hs-protolude/buildlink3.mk"
.include "../../math/hs-scientific/buildlink3.mk"
.include "../../math/hs-semigroups/buildlink3.mk"
.include "../../devel/hs-serialise/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.endif	# HS_PURESCRIPT_CST_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-purescript-cst
