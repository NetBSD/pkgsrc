# $NetBSD: buildlink3.mk,v 1.1 2020/01/03 08:03:05 pho Exp $

BUILDLINK_TREE+=	hs-yaml

.if !defined(HS_YAML_BUILDLINK3_MK)
HS_YAML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-yaml+=	hs-yaml>=0.8.30
BUILDLINK_ABI_DEPENDS.hs-yaml+=	hs-yaml>=0.8.30
BUILDLINK_PKGSRCDIR.hs-yaml?=	../../textproc/hs-yaml

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../textproc/hs-attoparsec/buildlink3.mk"
.include "../../devel/hs-conduit/buildlink3.mk"
.include "../../devel/hs-resourcet/buildlink3.mk"
.include "../../math/hs-scientific/buildlink3.mk"
.include "../../math/hs-semigroups/buildlink3.mk"
.include "../../devel/hs-text/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../textproc/libyaml/buildlink3.mk"
.endif	# HS_YAML_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-yaml
