# $NetBSD: buildlink3.mk,v 1.8 2021/04/23 06:06:12 pho Exp $

BUILDLINK_TREE+=	hs-dlist

.if !defined(HS_DLIST_BUILDLINK3_MK)
HS_DLIST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-dlist+=	hs-dlist>=1.0
BUILDLINK_ABI_DEPENDS.hs-dlist+=	hs-dlist>=1.0
BUILDLINK_PKGSRCDIR.hs-dlist?=		../../devel/hs-dlist
.endif	# HS_DLIST_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-dlist
