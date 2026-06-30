# $NetBSD: options.mk,v 1.8 2026/06/30 20:19:42 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.git
PKG_SUPPORTED_OPTIONS=	openssl
.if ${OPSYS} == "Darwin"
PKG_SUPPORTED_OPTIONS+=	apple-common-crypto
.endif
.if ${OPSYS} != "QNX"
PKG_SUGGESTED_OPTIONS+=	openssl
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mapple-common-crypto)
CONFIGURE_ARGS+=	--without-openssl
.else
MAKE_FLAGS+=		NO_APPLE_COMMON_CRYPTO=1
.  if !empty(PKG_OPTIONS:Mopenssl)
.    include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE}
.  else
CONFIGURE_ARGS+=	--without-openssl
.  endif
.endif
