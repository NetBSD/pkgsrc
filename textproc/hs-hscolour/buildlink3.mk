# $NetBSD: buildlink3.mk,v 1.14 2025/03/05 03:39:59 pho Exp $

BUILDLINK_TREE+=	hs-hscolour

.if !defined(HS_HSCOLOUR_BUILDLINK3_MK)
HS_HSCOLOUR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hscolour+=	hs-hscolour>=1.25
BUILDLINK_ABI_DEPENDS.hs-hscolour+=	hs-hscolour>=1.25nb4
BUILDLINK_PKGSRCDIR.hs-hscolour?=	../../textproc/hs-hscolour
.endif	# HS_HSCOLOUR_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hscolour
