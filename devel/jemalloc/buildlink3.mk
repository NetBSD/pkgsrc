# $NetBSD: buildlink3.mk,v 1.1 2016/02/18 15:51:59 gson Exp $

BUILDLINK_TREE+=	jemalloc

.if !defined(JEMALLOC_BUILDLINK3_MK)
JEMALLOC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.jemalloc+=	jemalloc>=4.0.0
BUILDLINK_PKGSRCDIR.jemalloc?=	../../devel/jemalloc
.endif	# JEMALLOC_BUILDLINK3_MK

BUILDLINK_TREE+=	-jemalloc
