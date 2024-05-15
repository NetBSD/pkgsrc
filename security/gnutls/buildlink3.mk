# $NetBSD: buildlink3.mk,v 1.51 2024/05/15 08:13:25 nia Exp $

BUILDLINK_TREE+=	gnutls

.if !defined(GNUTLS_BUILDLINK3_MK)
GNUTLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnutls+=	gnutls>=3.3.0
BUILDLINK_ABI_DEPENDS.gnutls+=	gnutls>=3.8.1nb2
BUILDLINK_PKGSRCDIR.gnutls?=	../../security/gnutls

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/libtasn1/buildlink3.mk"
BUILDLINK_API_DEPENDS.nettle+=		nettle>=3.4.1
.include "../../security/nettle/buildlink3.mk"
.if ${PKG_BUILD_OPTIONS.gnutls:Mpkcs11}
.include "../../security/p11-kit/buildlink3.mk"
.endif
.include "../../textproc/libunistring/buildlink3.mk"
pkgbase := gnutls
.include "../../mk/pkg-build-options.mk"
.if ${PKG_BUILD_OPTIONS.gnutls:Mdane}
.include "../../net/unbound/buildlink3.mk"
.endif
.endif # GNUTLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnutls
