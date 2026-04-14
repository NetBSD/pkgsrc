# $NetBSD: buildlink3.mk,v 1.5 2026/04/14 12:49:12 adam Exp $

BUILDLINK_TREE+=	jemalloc

.if !defined(JEMALLOC_BUILDLINK3_MK)
JEMALLOC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.jemalloc+=	jemalloc>=4.0.0
BUILDLINK_ABI_DEPENDS.jemalloc+=	jemalloc>=5.2.1nb4
BUILDLINK_PKGSRCDIR.jemalloc?=		../../devel/jemalloc
.endif	# JEMALLOC_BUILDLINK3_MK

BUILDLINK_TREE+=	-jemalloc
