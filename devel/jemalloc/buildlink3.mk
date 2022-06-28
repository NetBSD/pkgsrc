# $NetBSD: buildlink3.mk,v 1.3 2022/06/28 11:31:45 wiz Exp $

BUILDLINK_TREE+=	jemalloc

.if !defined(JEMALLOC_BUILDLINK3_MK)
JEMALLOC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.jemalloc+=	jemalloc>=4.0.0
BUILDLINK_ABI_DEPENDS.jemalloc?=		jemalloc>=5.2.1nb4
BUILDLINK_PKGSRCDIR.jemalloc?=		../../devel/jemalloc
.endif	# JEMALLOC_BUILDLINK3_MK

BUILDLINK_TREE+=	-jemalloc
