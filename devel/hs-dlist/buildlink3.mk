# $NetBSD: buildlink3.mk,v 1.1 2014/05/18 21:29:39 szptvlfn Exp $

BUILDLINK_TREE+=	hs-dlist

.if !defined(HS_DLIST_BUILDLINK3_MK)
HS_DLIST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-dlist+=	hs-dlist>=0.7.0
BUILDLINK_PKGSRCDIR.hs-dlist?=	../../devel/hs-dlist
.endif	# HS_DLIST_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-dlist
