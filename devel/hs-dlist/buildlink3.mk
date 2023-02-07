# $NetBSD: buildlink3.mk,v 1.13 2023/02/07 01:40:32 pho Exp $

BUILDLINK_TREE+=	hs-dlist

.if !defined(HS_DLIST_BUILDLINK3_MK)
HS_DLIST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-dlist+=	hs-dlist>=1.0
BUILDLINK_ABI_DEPENDS.hs-dlist+=	hs-dlist>=1.0nb5
BUILDLINK_PKGSRCDIR.hs-dlist?=		../../devel/hs-dlist
.endif	# HS_DLIST_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-dlist
