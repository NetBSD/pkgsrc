# $NetBSD: buildlink3.mk,v 1.8 2024/05/09 01:32:01 pho Exp $

BUILDLINK_TREE+=	hs-lens-family-core

.if !defined(HS_LENS_FAMILY_CORE_BUILDLINK3_MK)
HS_LENS_FAMILY_CORE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-lens-family-core+=	hs-lens-family-core>=2.1.3
BUILDLINK_ABI_DEPENDS.hs-lens-family-core+=	hs-lens-family-core>=2.1.3nb1
BUILDLINK_PKGSRCDIR.hs-lens-family-core?=	../../devel/hs-lens-family-core
.endif	# HS_LENS_FAMILY_CORE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-lens-family-core
