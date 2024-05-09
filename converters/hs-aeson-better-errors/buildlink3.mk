# $NetBSD: buildlink3.mk,v 1.9 2024/05/09 01:31:39 pho Exp $

BUILDLINK_TREE+=	hs-aeson-better-errors

.if !defined(HS_AESON_BETTER_ERRORS_BUILDLINK3_MK)
HS_AESON_BETTER_ERRORS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-aeson-better-errors+=	hs-aeson-better-errors>=0.9.1
BUILDLINK_ABI_DEPENDS.hs-aeson-better-errors+=	hs-aeson-better-errors>=0.9.1.1nb5
BUILDLINK_PKGSRCDIR.hs-aeson-better-errors?=	../../converters/hs-aeson-better-errors

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-dlist/buildlink3.mk"
.include "../../math/hs-scientific/buildlink3.mk"
.include "../../devel/hs-transformers-compat/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../devel/hs-void/buildlink3.mk"
.endif	# HS_AESON_BETTER_ERRORS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-aeson-better-errors
