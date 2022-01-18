# $NetBSD: buildlink3.mk,v 1.4 2022/01/18 02:48:15 pho Exp $

BUILDLINK_TREE+=	hs-utility-ht

.if !defined(HS_UTILITY_HT_BUILDLINK3_MK)
HS_UTILITY_HT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-utility-ht+=	hs-utility-ht>=0.0.16
BUILDLINK_ABI_DEPENDS.hs-utility-ht+=	hs-utility-ht>=0.0.16nb2
BUILDLINK_PKGSRCDIR.hs-utility-ht?=	../../devel/hs-utility-ht
.endif	# HS_UTILITY_HT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-utility-ht
