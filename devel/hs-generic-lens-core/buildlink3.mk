# $NetBSD: buildlink3.mk,v 1.3 2023/02/07 01:40:35 pho Exp $

BUILDLINK_TREE+=	hs-generic-lens-core

.if !defined(HS_GENERIC_LENS_CORE_BUILDLINK3_MK)
HS_GENERIC_LENS_CORE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-generic-lens-core+=	hs-generic-lens-core>=2.2.1
BUILDLINK_ABI_DEPENDS.hs-generic-lens-core+=	hs-generic-lens-core>=2.2.1.0nb2
BUILDLINK_PKGSRCDIR.hs-generic-lens-core?=	../../devel/hs-generic-lens-core

.include "../../math/hs-indexed-profunctors/buildlink3.mk"
.endif	# HS_GENERIC_LENS_CORE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-generic-lens-core
