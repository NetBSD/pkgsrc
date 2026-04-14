# $NetBSD: buildlink3.mk,v 1.1 2026/04/14 11:43:50 kikadf Exp $

BUILDLINK_TREE+=	tllist

.if !defined(TLLIST_BUILDLINK3_MK)
TLLIST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tllist+=	tllist>=1.1.0
BUILDLINK_PKGSRCDIR.tllist?=	../../devel/tllist
.endif	# TLLIST_BUILDLINK3_MK

BUILDLINK_TREE+=	-tllist
