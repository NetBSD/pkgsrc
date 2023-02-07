# $NetBSD: buildlink3.mk,v 1.3 2023/02/07 01:40:35 pho Exp $

BUILDLINK_TREE+=	hs-generic-lens

.if !defined(HS_GENERIC_LENS_BUILDLINK3_MK)
HS_GENERIC_LENS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-generic-lens+=	hs-generic-lens>=2.2.1
BUILDLINK_ABI_DEPENDS.hs-generic-lens+=	hs-generic-lens>=2.2.1.0nb2
BUILDLINK_PKGSRCDIR.hs-generic-lens?=	../../devel/hs-generic-lens

.include "../../devel/hs-generic-lens-core/buildlink3.mk"
.include "../../math/hs-profunctors/buildlink3.mk"
.endif	# HS_GENERIC_LENS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-generic-lens
