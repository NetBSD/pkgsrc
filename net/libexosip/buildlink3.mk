# $NetBSD: buildlink3.mk,v 1.2 2014/02/12 23:18:22 tron Exp $

BUILDLINK_TREE+=	libexosip2

.if !defined(LIBEXOSIP2_BUILDLINK3_MK)
LIBEXOSIP2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libexosip2+=	libeXosip2>=3.5.0
BUILDLINK_ABI_DEPENDS.libexosip2?=	libeXosip2>=4.0.0nb1
BUILDLINK_PKGSRCDIR.libexosip2?=	../../net/libexosip

pkgbase := libeXosip2
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.libeXosip2:Mopenssl)
.include "../../security/openssl/buildlink3.mk"
.endif

.include "../../net/libcares/buildlink3.mk"
.include "../../devel/libosip/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # LIBEXOSIP2_BUILDLINK3_MK

BUILDLINK_TREE+=	-libexosip2
