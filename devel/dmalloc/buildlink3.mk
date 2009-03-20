# $NetBSD: buildlink3.mk,v 1.6 2009/03/20 19:24:12 joerg Exp $

BUILDLINK_TREE+=	dmalloc

.if !defined(DMALLOC_BUILDLINK3_MK)
DMALLOC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.dmalloc+=	dmalloc>=4.8.2nb2
BUILDLINK_PKGSRCDIR.dmalloc?=	../../devel/dmalloc
BUILDLINK_DEPMETHOD.dmalloc?=	build
.endif # DMALLOC_BUILDLINK3_MK

BUILDLINK_TREE+=	-dmalloc
