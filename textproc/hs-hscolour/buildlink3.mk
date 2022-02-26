# $NetBSD: buildlink3.mk,v 1.7 2022/02/26 03:58:27 pho Exp $

BUILDLINK_TREE+=	hs-hscolour

.if !defined(HS_HSCOLOUR_BUILDLINK3_MK)
HS_HSCOLOUR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hscolour+=	hs-hscolour>=1.24.4
BUILDLINK_ABI_DEPENDS.hs-hscolour+=	hs-hscolour>=1.24.4nb4
BUILDLINK_PKGSRCDIR.hs-hscolour?=	../../textproc/hs-hscolour
.endif	# HS_HSCOLOUR_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hscolour
