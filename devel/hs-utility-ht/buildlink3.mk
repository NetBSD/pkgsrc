# $NetBSD: buildlink3.mk,v 1.1 2020/03/30 16:42:57 riastradh Exp $

BUILDLINK_TREE+=	hs-utility-ht

.if !defined(HS_UTILITY_HT_BUILDLINK3_MK)
HS_UTILITY_HT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-utility-ht+=	hs-utility-ht>=0.0.15
BUILDLINK_ABI_DEPENDS.hs-utility-ht+=	hs-utility-ht>=0.0.15
BUILDLINK_PKGSRCDIR.hs-utility-ht?=	../../devel/hs-utility-ht
.endif	# HS_UTILITY_HT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-utility-ht
