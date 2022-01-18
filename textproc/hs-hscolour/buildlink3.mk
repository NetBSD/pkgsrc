# $NetBSD: buildlink3.mk,v 1.5 2022/01/18 02:48:26 pho Exp $

BUILDLINK_TREE+=	hs-hscolour

.if !defined(HS_HSCOLOUR_BUILDLINK3_MK)
HS_HSCOLOUR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hscolour+=	hs-hscolour>=1.24.4
BUILDLINK_ABI_DEPENDS.hs-hscolour+=	hs-hscolour>=1.24.4nb2
BUILDLINK_PKGSRCDIR.hs-hscolour?=	../../textproc/hs-hscolour
.endif	# HS_HSCOLOUR_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hscolour
