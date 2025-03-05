# $NetBSD: buildlink3.mk,v 1.10 2025/03/05 03:38:57 pho Exp $

BUILDLINK_TREE+=	hs-lens-aeson

.if !defined(HS_LENS_AESON_BUILDLINK3_MK)
HS_LENS_AESON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-lens-aeson+=	hs-lens-aeson>=1.2.3
BUILDLINK_ABI_DEPENDS.hs-lens-aeson+=	hs-lens-aeson>=1.2.3nb4
BUILDLINK_PKGSRCDIR.hs-lens-aeson?=	../../converters/hs-lens-aeson

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-lens/buildlink3.mk"
.include "../../math/hs-scientific/buildlink3.mk"
.include "../../textproc/hs-text-short/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.endif	# HS_LENS_AESON_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-lens-aeson
