# $NetBSD: buildlink3.mk,v 1.10 2022/08/22 10:13:25 wiz Exp $

BUILDLINK_TREE+=	hs-yaml

.if !defined(HS_YAML_BUILDLINK3_MK)
HS_YAML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-yaml+=	hs-yaml>=0.11.7
BUILDLINK_ABI_DEPENDS.hs-yaml+=	hs-yaml>=0.11.7.0nb4
BUILDLINK_PKGSRCDIR.hs-yaml?=	../../textproc/hs-yaml

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../textproc/hs-attoparsec/buildlink3.mk"
.include "../../devel/hs-conduit/buildlink3.mk"
.include "../../textproc/hs-libyaml/buildlink3.mk"
.include "../../devel/hs-resourcet/buildlink3.mk"
.include "../../math/hs-scientific/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.endif	# HS_YAML_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-yaml
