# $NetBSD: buildlink3.mk,v 1.23 2022/01/18 02:48:01 pho Exp $

BUILDLINK_TREE+=	hs-aeson

.if !defined(HS_AESON_BUILDLINK3_MK)
HS_AESON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-aeson+=	hs-aeson>=1.5.6
BUILDLINK_ABI_DEPENDS.hs-aeson+=	hs-aeson>=1.5.6.0nb2
BUILDLINK_PKGSRCDIR.hs-aeson?=		../../converters/hs-aeson

.include "../../textproc/hs-attoparsec/buildlink3.mk"
.include "../../devel/hs-base-compat-batteries/buildlink3.mk"
.include "../../devel/hs-data-fix/buildlink3.mk"
.include "../../devel/hs-dlist/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-primitive/buildlink3.mk"
.include "../../math/hs-scientific/buildlink3.mk"
.include "../../devel/hs-strict/buildlink3.mk"
.include "../../devel/hs-tagged/buildlink3.mk"
.include "../../devel/hs-th-abstraction/buildlink3.mk"
.include "../../devel/hs-these/buildlink3.mk"
.include "../../time/hs-time-compat/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-uuid-types/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.endif	# HS_AESON_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-aeson
