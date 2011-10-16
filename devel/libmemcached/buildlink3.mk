# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/10/16 05:33:56 manu Exp $

BUILDLINK_TREE+=	libmemcached

.if !defined(libmemcached_BUILDLINK3_MK)
LIBMEMCACHED_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmemcached+=	libmemcached>=0.53
BUILDLINK_ABI_DEPENDS.libmemcached+=	libmemcached>=0.53
BUILDLINK_PKGSRCDIR.libmemcached?=	../../devel/libmemcached
.endif # LIBMEMCACHED_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmemcached
