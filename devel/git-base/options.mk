# $NetBSD: options.mk,v 1.9 2026/07/01 21:28:37 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.git
PKG_SUPPORTED_OPTIONS=	openssl rust
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

.if !empty(PKG_OPTIONS:Mrust)
MAKE_ENV+=	WITH_RUST=YesPlease
.include "../../lang/rust/buildlink3.mk"
.else
MAKE_ENV+=	NO_RUST=1
.endif
