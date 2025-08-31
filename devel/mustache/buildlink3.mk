# $NetBSD: buildlink3.mk,v 1.1 2025/08/31 19:18:18 wiz Exp $

BUILDLINK_TREE+=	mustache

.if !defined(MUSTACHE_BUILDLINK3_MK)
MUSTACHE_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.mustache?=	build

BUILDLINK_API_DEPENDS.mustache+=	mustache>=4.1
BUILDLINK_PKGSRCDIR.mustache?=		../../devel/mustache
.endif	# MUSTACHE_BUILDLINK3_MK

BUILDLINK_TREE+=	-mustache
