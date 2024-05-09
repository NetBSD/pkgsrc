# $NetBSD: buildlink3.mk,v 1.7 2024/05/09 01:31:55 pho Exp $

BUILDLINK_TREE+=	hs-generic-lens

.if !defined(HS_GENERIC_LENS_BUILDLINK3_MK)
HS_GENERIC_LENS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-generic-lens+=	hs-generic-lens>=2.2.2
BUILDLINK_ABI_DEPENDS.hs-generic-lens+=	hs-generic-lens>=2.2.2.0nb2
BUILDLINK_PKGSRCDIR.hs-generic-lens?=	../../devel/hs-generic-lens

.include "../../devel/hs-generic-lens-core/buildlink3.mk"
.include "../../math/hs-profunctors/buildlink3.mk"
.endif	# HS_GENERIC_LENS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-generic-lens
