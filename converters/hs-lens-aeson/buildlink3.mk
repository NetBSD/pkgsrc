# $NetBSD: buildlink3.mk,v 1.4 2023/02/07 01:40:23 pho Exp $

BUILDLINK_TREE+=	hs-lens-aeson

.if !defined(HS_LENS_AESON_BUILDLINK3_MK)
HS_LENS_AESON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-lens-aeson+=	hs-lens-aeson>=1.1.3
BUILDLINK_ABI_DEPENDS.hs-lens-aeson+=	hs-lens-aeson>=1.2.2nb1
BUILDLINK_PKGSRCDIR.hs-lens-aeson?=	../../converters/hs-lens-aeson

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../textproc/hs-attoparsec/buildlink3.mk"
.include "../../devel/hs-lens/buildlink3.mk"
.include "../../math/hs-scientific/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.endif	# HS_LENS_AESON_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-lens-aeson
