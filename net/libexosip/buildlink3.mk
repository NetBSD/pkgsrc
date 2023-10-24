# $NetBSD: buildlink3.mk,v 1.7 2023/10/24 22:10:22 wiz Exp $

BUILDLINK_TREE+=	libeXosip2

.if !defined(LIBEXOSIP2_BUILDLINK3_MK)
LIBEXOSIP2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libeXosip2+=	libeXosip2>=3.5.0
BUILDLINK_ABI_DEPENDS.libeXosip2+=	libeXosip2>=5.3.0nb1
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
