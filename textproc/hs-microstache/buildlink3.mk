# $NetBSD: buildlink3.mk,v 1.7 2025/08/13 11:07:33 pho Exp $

BUILDLINK_TREE+=	hs-microstache

.if !defined(HS_MICROSTACHE_BUILDLINK3_MK)
HS_MICROSTACHE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-microstache+=	hs-microstache>=1.0.3
BUILDLINK_ABI_DEPENDS.hs-microstache+=	hs-microstache>=1.0.3nb3
BUILDLINK_PKGSRCDIR.hs-microstache?=	../../textproc/hs-microstache

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.endif	# HS_MICROSTACHE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-microstache
