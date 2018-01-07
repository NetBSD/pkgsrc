# $NetBSD: buildlink3.mk,v 1.2 2018/01/07 13:04:04 rillig Exp $

BUILDLINK_TREE+=	jemalloc

.if !defined(JEMALLOC_BUILDLINK3_MK)
JEMALLOC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.jemalloc+=	jemalloc>=4.0.0
BUILDLINK_PKGSRCDIR.jemalloc?=		../../devel/jemalloc
.endif	# JEMALLOC_BUILDLINK3_MK

BUILDLINK_TREE+=	-jemalloc
