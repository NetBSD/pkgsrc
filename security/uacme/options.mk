# $NetBSD: options.mk,v 1.1 2024/05/02 13:34:56 hauke Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.uacme

PKG_OPTIONS_REQUIRED_GROUPS=	tls
PKG_OPTIONS_GROUP.tls=		openssl gnutls mbedtls

PKG_SUGGESTED_OPTIONS=		openssl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mopenssl)
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}
.include "../../security/openssl/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mgnutls)
CONFIGURE_ARGS+=	--with-gnutls=${BUILDLINK_PREFIX.gnutls}
.include "../../security/gnutls/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mmbedtls)
CONFIGURE_ARGS+=	--with-mbedtls=${BUILDLINK_PREFIX.mbedtls3}
.include "../../security/mbedtls3/buildlink3.mk"
.endif
