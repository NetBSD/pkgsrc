# $NetBSD: buildlink3.mk,v 1.1 2026/04/14 10:58:09 kikadf Exp $

BUILDLINK_TREE+=	basu

.if !defined(BASU_BUILDLINK3_MK)
BASU_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.basu+=	basu>=0.2.1
BUILDLINK_ABI_DEPENDS.basu+=	basu>=0.2.1
BUILDLINK_PKGSRCDIR.basu?=	../../devel/basu

.endif # BASU_BUILDLINK3_MK

BUILDLINK_TREE+=	-basu
