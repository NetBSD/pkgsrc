# $NetBSD: options.mk,v 1.3 2021/04/10 08:39:23 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.pkcs11-helper
PKG_SUPPORTED_OPTIONS=	openssl gnutls nss mbedtls
PKG_SUGGESTED_OPTIONS=	openssl

.include "../../mk/bsd.options.mk"

# crypto engines to use

.if !empty(PKG_OPTIONS:Mopenssl)
CONFIGURE_ARGS+=--enable-crypto-engine-openssl
.else
CONFIGURE_ARGS+=--disable-crypto-engine-openssl
.endif

.if !empty(PKG_OPTIONS:Mgnutls)
.include "../../security/gnutls/buildlink3.mk"
CONFIGURE_ARGS+=--enable-crypto-engine-gnutls
.else
CONFIGURE_ARGS+=--disable-crypto-engine-gnutls
.endif

.if !empty(PKG_OPTIONS:Mmbedtls)
.include "../../security/mbedtls/buildlink3.mk"
CONFIGURE_ARGS+=--enable-crypto-engine-mbedtls
.else
CONFIGURE_ARGS+=--disable-crypto-engine-mbedtls
.endif

.if !empty(PKG_OPTIONS:Mnss)
.include "../../devel/nss/buildlink3.mk"
CONFIGURE_ARGS+=--enable-crypto-engine-nss
.else
CONFIGURE_ARGS+=--disable-crypto-engine-nss
.endif
