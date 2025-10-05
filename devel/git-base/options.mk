# $NetBSD: options.mk,v 1.7 2025/10/05 18:09:33 js Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.git
PKG_SUPPORTED_OPTIONS=	apple-common-crypto openssl
PKG_SUGGESTED_OPTIONS=	
.if ${OPSYS} != "QNX"
PKG_SUGGESTED_OPTIONS+=	openssl
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mapple-common-crypto)
.  if ${MACHINE_PLATFORM:MDarwin-[0-8].*-*}
PKG_FAIL_REASON+=	"apple-common-crypto not available on this system"
.  endif
CONFIGURE_ARGS+=	--without-openssl
.elif !empty(PKG_OPTIONS:Mopenssl)
.include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE}
MAKE_FLAGS+=		NO_APPLE_COMMON_CRYPTO=1
.else
CONFIGURE_ARGS+=	--without-openssl
MAKE_FLAGS+=		NO_APPLE_COMMON_CRYPTO=1
.endif
