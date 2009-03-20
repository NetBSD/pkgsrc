# $NetBSD: buildlink3.mk,v 1.6 2009/03/20 19:24:20 joerg Exp $

BUILDLINK_TREE+=	libmemcache

.if !defined(LIBMEMCACHE_BUILDLINK3_MK)
LIBMEMCACHE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmemcache+=	libmemcache>=1.4.0beta5
BUILDLINK_PKGSRCDIR.libmemcache?=	../../devel/libmemcache
.endif # LIBMEMCACHE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmemcache
