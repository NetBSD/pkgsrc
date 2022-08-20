# $NetBSD: buildlink3.mk,v 1.4 2022/08/20 08:08:12 wiz Exp $

BUILDLINK_TREE+=	hs-hslua-aeson

.if !defined(HS_HSLUA_AESON_BUILDLINK3_MK)
HS_HSLUA_AESON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hslua-aeson+=	hs-hslua-aeson>=2.1.0
BUILDLINK_ABI_DEPENDS.hs-hslua-aeson+=	hs-hslua-aeson>=2.1.0nb3
BUILDLINK_PKGSRCDIR.hs-hslua-aeson?=	../../converters/hs-hslua-aeson

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../lang/hs-hslua-core/buildlink3.mk"
.include "../../lang/hs-hslua-marshalling/buildlink3.mk"
.include "../../math/hs-scientific/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.endif	# HS_HSLUA_AESON_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hslua-aeson
