# $NetBSD: buildlink3.mk,v 1.5 2023/10/30 10:56:53 pho Exp $

BUILDLINK_TREE+=	hs-generic-lens

.if !defined(HS_GENERIC_LENS_BUILDLINK3_MK)
HS_GENERIC_LENS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-generic-lens+=	hs-generic-lens>=2.2.2
BUILDLINK_ABI_DEPENDS.hs-generic-lens+=	hs-generic-lens>=2.2.2.0
BUILDLINK_PKGSRCDIR.hs-generic-lens?=	../../devel/hs-generic-lens

.include "../../devel/hs-generic-lens-core/buildlink3.mk"
.include "../../math/hs-profunctors/buildlink3.mk"
.endif	# HS_GENERIC_LENS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-generic-lens
