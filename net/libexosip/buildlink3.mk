# $NetBSD: buildlink3.mk,v 1.6 2020/03/06 13:01:47 nia Exp $

BUILDLINK_TREE+=	libeXosip2

.if !defined(LIBEXOSIP2_BUILDLINK3_MK)
LIBEXOSIP2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libeXosip2+=	libeXosip2>=3.5.0
BUILDLINK_ABI_DEPENDS.libeXosip2+=	libeXosip2>=4.1.0nb2
BUILDLINK_PKGSRCDIR.libeXosip2?=	../../net/libexosip

pkgbase := libeXosip2
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.libeXosip2:Mopenssl)
.include "../../security/openssl/buildlink3.mk"
.endif

.include "../../net/libcares/buildlink3.mk"
.include "../../devel/libosip/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # LIBEXOSIP2_BUILDLINK3_MK

BUILDLINK_TREE+=	-libeXosip2
