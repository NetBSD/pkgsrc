# $NetBSD: options.mk,v 1.6 2023/06/12 21:41:59 schmonz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.git
PKG_SUPPORTED_OPTIONS=	apple-common-crypto
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mapple-common-crypto)
.  if ${MACHINE_PLATFORM:MDarwin-[0-8].*-*}
PKG_FAIL_REASON+=	"apple-common-crypto not available on this system"
.  endif
CONFIGURE_ARGS+=	--without-openssl
.else
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE}
.include "../../security/openssl/buildlink3.mk"
MAKE_FLAGS+=		NO_APPLE_COMMON_CRYPTO=1
.endif
