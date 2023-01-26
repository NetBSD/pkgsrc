# $NetBSD: buildlink3.mk,v 1.4 2023/01/26 11:43:02 pho Exp $

BUILDLINK_TREE+=	hs-serialise

.if !defined(HS_SERIALISE_BUILDLINK3_MK)
HS_SERIALISE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-serialise+=	hs-serialise>=0.2.6
BUILDLINK_ABI_DEPENDS.hs-serialise+=	hs-serialise>=0.2.6.0
BUILDLINK_PKGSRCDIR.hs-serialise?=	../../devel/hs-serialise

.include "../../devel/hs-cborg/buildlink3.mk"
.include "../../devel/hs-half/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-primitive/buildlink3.mk"
.include "../../devel/hs-strict/buildlink3.mk"
.include "../../devel/hs-these/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.endif	# HS_SERIALISE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-serialise
