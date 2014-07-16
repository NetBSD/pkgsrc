# $NetBSD: buildlink3.mk,v 1.2 2014/07/16 21:02:35 szptvlfn Exp $

BUILDLINK_TREE+=	hs-dlist

.if !defined(HS_DLIST_BUILDLINK3_MK)
HS_DLIST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-dlist+=	hs-dlist>=0.7.1
BUILDLINK_PKGSRCDIR.hs-dlist?=	../../devel/hs-dlist
.endif	# HS_DLIST_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-dlist
