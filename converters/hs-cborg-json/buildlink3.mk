# $NetBSD: buildlink3.mk,v 1.3 2022/08/20 08:08:12 wiz Exp $

BUILDLINK_TREE+=	hs-cborg-json

.if !defined(HS_CBORG_JSON_BUILDLINK3_MK)
HS_CBORG_JSON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-cborg-json+=	hs-cborg-json>=0.2.3
BUILDLINK_ABI_DEPENDS.hs-cborg-json+=	hs-cborg-json>=0.2.3.0nb2
BUILDLINK_PKGSRCDIR.hs-cborg-json?=	../../converters/hs-cborg-json

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../converters/hs-aeson-pretty/buildlink3.mk"
.include "../../devel/hs-cborg/buildlink3.mk"
.include "../../math/hs-scientific/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.endif	# HS_CBORG_JSON_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-cborg-json
