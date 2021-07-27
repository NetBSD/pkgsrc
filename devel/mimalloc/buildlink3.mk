# $NetBSD: buildlink3.mk,v 1.1 2021/07/27 09:29:41 fcambus Exp $

BUILDLINK_TREE+=	mimalloc

.if !defined(MIMALLOC_BUILDLINK3_MK)
MIMALLOC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mimalloc+=	mimalloc>=2.0.2
BUILDLINK_PKGSRCDIR.mimalloc?=		../../devel/mimalloc
.endif	# MIMALLOC_BUILDLINK3_MK

BUILDLINK_TREE+=	-mimalloc
