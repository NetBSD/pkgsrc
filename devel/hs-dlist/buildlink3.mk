# $NetBSD: buildlink3.mk,v 1.7 2019/12/31 07:33:17 pho Exp $

BUILDLINK_TREE+=	hs-dlist

.if !defined(HS_DLIST_BUILDLINK3_MK)
HS_DLIST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-dlist+=	hs-dlist>=0.8.0
BUILDLINK_ABI_DEPENDS.hs-dlist+=	hs-dlist>=0.8.0.7
BUILDLINK_PKGSRCDIR.hs-dlist?=		../../devel/hs-dlist
.endif	# HS_DLIST_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-dlist
