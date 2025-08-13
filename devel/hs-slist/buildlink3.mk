# $NetBSD: buildlink3.mk,v 1.5 2025/08/13 11:06:58 pho Exp $

BUILDLINK_TREE+=	hs-slist

.if !defined(HS_SLIST_BUILDLINK3_MK)
HS_SLIST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-slist+=	hs-slist>=0.2.1
BUILDLINK_ABI_DEPENDS.hs-slist+=	hs-slist>=0.2.1.0nb4
BUILDLINK_PKGSRCDIR.hs-slist?=		../../devel/hs-slist
.endif	# HS_SLIST_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-slist
