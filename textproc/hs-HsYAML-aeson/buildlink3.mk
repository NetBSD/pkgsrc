# $NetBSD: buildlink3.mk,v 1.7 2024/05/09 01:32:38 pho Exp $

BUILDLINK_TREE+=	hs-HsYAML-aeson

.if !defined(HS_HSYAML_AESON_BUILDLINK3_MK)
HS_HSYAML_AESON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-HsYAML-aeson+=	hs-HsYAML-aeson>=0.2.0
BUILDLINK_ABI_DEPENDS.hs-HsYAML-aeson+=	hs-HsYAML-aeson>=0.2.0.1nb6
BUILDLINK_PKGSRCDIR.hs-HsYAML-aeson?=	../../textproc/hs-HsYAML-aeson

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../textproc/hs-HsYAML/buildlink3.mk"
.include "../../math/hs-scientific/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.endif	# HS_HSYAML_AESON_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-HsYAML-aeson
