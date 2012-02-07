# $NetBSD: buildlink3.mk,v 1.2 2012/02/07 11:34:00 fhajny Exp $

BUILDLINK_TREE+=	libmemcached

.if !defined(LIBMEMCACHED_BUILDLINK3_MK)
LIBMEMCACHED_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmemcached+=	libmemcached>=0.53
BUILDLINK_ABI_DEPENDS.libmemcached+=	libmemcached>=0.53
BUILDLINK_PKGSRCDIR.libmemcached?=	../../devel/libmemcached
.endif # LIBMEMCACHED_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmemcached
