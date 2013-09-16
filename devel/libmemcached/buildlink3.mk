# $NetBSD: buildlink3.mk,v 1.3 2013/09/16 16:46:32 fhajny Exp $

BUILDLINK_TREE+=	libmemcached

.if !defined(LIBMEMCACHED_BUILDLINK3_MK)
LIBMEMCACHED_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmemcached+=	libmemcached>=0.53
BUILDLINK_ABI_DEPENDS.libmemcached+=	libmemcached>=0.53
BUILDLINK_PKGSRCDIR.libmemcached?=	../../devel/libmemcached

pkgbase:=		libmemcached
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.libmemcached:Msasl)
.  include "../../security/cyrus-sasl/buildlink3.mk"
.endif
.endif # LIBMEMCACHED_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmemcached
