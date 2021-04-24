# $NetBSD: buildlink3.mk,v 1.2 2021/04/24 05:33:25 pho Exp $

BUILDLINK_TREE+=	hs-utility-ht

.if !defined(HS_UTILITY_HT_BUILDLINK3_MK)
HS_UTILITY_HT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-utility-ht+=	hs-utility-ht>=0.0.16
BUILDLINK_ABI_DEPENDS.hs-utility-ht+=	hs-utility-ht>=0.0.16
BUILDLINK_PKGSRCDIR.hs-utility-ht?=	../../devel/hs-utility-ht
.endif	# HS_UTILITY_HT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-utility-ht
