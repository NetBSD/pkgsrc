# $NetBSD: buildlink3.mk,v 1.7 2024/04/28 16:50:07 pho Exp $

BUILDLINK_TREE+=	hs-lens-family-core

.if !defined(HS_LENS_FAMILY_CORE_BUILDLINK3_MK)
HS_LENS_FAMILY_CORE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-lens-family-core+=	hs-lens-family-core>=2.1.3
BUILDLINK_ABI_DEPENDS.hs-lens-family-core+=	hs-lens-family-core>=2.1.3
BUILDLINK_PKGSRCDIR.hs-lens-family-core?=	../../devel/hs-lens-family-core
.endif	# HS_LENS_FAMILY_CORE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-lens-family-core
