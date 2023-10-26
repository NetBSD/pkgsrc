# $NetBSD: buildlink3.mk,v 1.10 2023/10/26 04:43:55 pho Exp $

BUILDLINK_TREE+=	hs-hscolour

.if !defined(HS_HSCOLOUR_BUILDLINK3_MK)
HS_HSCOLOUR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hscolour+=	hs-hscolour>=1.25
BUILDLINK_ABI_DEPENDS.hs-hscolour+=	hs-hscolour>=1.25
BUILDLINK_PKGSRCDIR.hs-hscolour?=	../../textproc/hs-hscolour
.endif	# HS_HSCOLOUR_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hscolour
