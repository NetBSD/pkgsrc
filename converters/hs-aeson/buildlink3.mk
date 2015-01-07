# $NetBSD: buildlink3.mk,v 1.8 2015/01/07 13:21:55 szptvlfn Exp $

BUILDLINK_TREE+=	hs-aeson

.if !defined(HS_AESON_BUILDLINK3_MK)
HS_AESON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-aeson+=	hs-aeson>=0.7.0
BUILDLINK_ABI_DEPENDS.hs-aeson+=	hs-aeson>=0.7.0.6nb7
BUILDLINK_PKGSRCDIR.hs-aeson?=	../../converters/hs-aeson

.include "../../textproc/hs-attoparsec/buildlink3.mk"
.include "../../devel/hs-dlist/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-mtl/buildlink3.mk"
.include "../../math/hs-scientific/buildlink3.mk"
.include "../../devel/hs-syb/buildlink3.mk"
.include "../../devel/hs-text/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.endif	# HS_AESON_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-aeson
