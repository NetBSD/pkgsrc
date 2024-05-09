# $NetBSD: buildlink3.mk,v 1.3 2024/05/09 01:32:44 pho Exp $

BUILDLINK_TREE+=	hs-microstache

.if !defined(HS_MICROSTACHE_BUILDLINK3_MK)
HS_MICROSTACHE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-microstache+=	hs-microstache>=1.0.2
BUILDLINK_ABI_DEPENDS.hs-microstache+=	hs-microstache>=1.0.2.3nb2
BUILDLINK_PKGSRCDIR.hs-microstache?=	../../textproc/hs-microstache

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.endif	# HS_MICROSTACHE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-microstache
