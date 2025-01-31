# $NetBSD: buildlink3.mk,v 1.3 2025/01/31 08:04:16 pho Exp $

BUILDLINK_TREE+=	hs-quickcheck-instances

.if !defined(HS_QUICKCHECK_INSTANCES_BUILDLINK3_MK)
HS_QUICKCHECK_INSTANCES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-quickcheck-instances+=	hs-quickcheck-instances>=0.3.32
BUILDLINK_ABI_DEPENDS.hs-quickcheck-instances+=	hs-quickcheck-instances>=0.3.32
BUILDLINK_PKGSRCDIR.hs-quickcheck-instances?=	../../devel/hs-quickcheck-instances

.include "../../devel/hs-QuickCheck/buildlink3.mk"
.include "../../devel/hs-splitmix/buildlink3.mk"
.include "../../textproc/hs-case-insensitive/buildlink3.mk"
.include "../../devel/hs-data-fix/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../math/hs-integer-logarithms/buildlink3.mk"
.include "../../time/hs-old-time/buildlink3.mk"
.include "../../devel/hs-OneTuple/buildlink3.mk"
.include "../../devel/hs-primitive/buildlink3.mk"
.include "../../math/hs-scientific/buildlink3.mk"
.include "../../devel/hs-strict/buildlink3.mk"
.include "../../devel/hs-tagged/buildlink3.mk"
.include "../../textproc/hs-text-short/buildlink3.mk"
.include "../../devel/hs-these/buildlink3.mk"
.include "../../time/hs-time-compat/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-uuid-types/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.endif	# HS_QUICKCHECK_INSTANCES_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-quickcheck-instances
