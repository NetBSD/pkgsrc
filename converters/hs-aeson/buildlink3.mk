# $NetBSD: buildlink3.mk,v 1.29 2023/02/07 01:40:22 pho Exp $

BUILDLINK_TREE+=	hs-aeson

.if !defined(HS_AESON_BUILDLINK3_MK)
HS_AESON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-aeson+=	hs-aeson>=2.1.1
BUILDLINK_ABI_DEPENDS.hs-aeson+=	hs-aeson>=2.1.1.0nb1
BUILDLINK_PKGSRCDIR.hs-aeson?=		../../converters/hs-aeson

.include "../../textproc/hs-attoparsec/buildlink3.mk"
.include "../../devel/hs-base-compat-batteries/buildlink3.mk"
.include "../../devel/hs-data-fix/buildlink3.mk"
.include "../../devel/hs-dlist/buildlink3.mk"
.include "../../devel/hs-generically/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-indexed-traversable/buildlink3.mk"
.include "../../devel/hs-OneTuple/buildlink3.mk"
.include "../../devel/hs-primitive/buildlink3.mk"
.include "../../devel/hs-QuickCheck/buildlink3.mk"
.include "../../math/hs-scientific/buildlink3.mk"
.include "../../devel/hs-semialign/buildlink3.mk"
.include "../../devel/hs-strict/buildlink3.mk"
.include "../../devel/hs-tagged/buildlink3.mk"
.include "../../textproc/hs-text-short/buildlink3.mk"
.include "../../devel/hs-th-abstraction/buildlink3.mk"
.include "../../devel/hs-these/buildlink3.mk"
.include "../../time/hs-time-compat/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-uuid-types/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../devel/hs-witherable/buildlink3.mk"
.endif	# HS_AESON_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-aeson
