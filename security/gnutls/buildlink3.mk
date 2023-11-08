# $NetBSD: buildlink3.mk,v 1.49 2023/11/08 13:20:45 wiz Exp $

BUILDLINK_TREE+=	gnutls

.if !defined(GNUTLS_BUILDLINK3_MK)
GNUTLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnutls+=	gnutls>=3.3.0
BUILDLINK_ABI_DEPENDS.gnutls+=	gnutls>=3.8.1nb2
BUILDLINK_PKGSRCDIR.gnutls?=	../../security/gnutls

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libcfg+/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/libtasn1/buildlink3.mk"
BUILDLINK_API_DEPENDS.nettle+=		nettle>=3.4.1
.include "../../security/nettle/buildlink3.mk"
.include "../../security/p11-kit/buildlink3.mk"
.include "../../textproc/libunistring/buildlink3.mk"
pkgbase := gnutls
.include "../../mk/pkg-build-options.mk"
.if ${PKG_BUILD_OPTIONS.gnutls:Mdane}
.include "../../net/unbound/buildlink3.mk"
.endif
.endif # GNUTLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnutls
