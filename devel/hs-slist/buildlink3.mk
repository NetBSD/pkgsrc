# $NetBSD: buildlink3.mk,v 1.4 2025/03/05 03:39:28 pho Exp $

BUILDLINK_TREE+=	hs-slist

.if !defined(HS_SLIST_BUILDLINK3_MK)
HS_SLIST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-slist+=	hs-slist>=0.2.1
BUILDLINK_ABI_DEPENDS.hs-slist+=	hs-slist>=0.2.1.0nb3
BUILDLINK_PKGSRCDIR.hs-slist?=		../../devel/hs-slist
.endif	# HS_SLIST_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-slist
