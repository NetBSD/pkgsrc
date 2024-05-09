# $NetBSD: buildlink3.mk,v 1.6 2024/05/09 01:31:52 pho Exp $

BUILDLINK_TREE+=	hs-dependent-map

.if !defined(HS_DEPENDENT_MAP_BUILDLINK3_MK)
HS_DEPENDENT_MAP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-dependent-map+=	hs-dependent-map>=0.4.0
BUILDLINK_ABI_DEPENDS.hs-dependent-map+=	hs-dependent-map>=0.4.0.0nb5
BUILDLINK_PKGSRCDIR.hs-dependent-map?=		../../devel/hs-dependent-map

.include "../../devel/hs-constraints-extras/buildlink3.mk"
.include "../../devel/hs-dependent-sum/buildlink3.mk"
.endif	# HS_DEPENDENT_MAP_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-dependent-map
