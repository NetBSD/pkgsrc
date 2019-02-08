# $NetBSD: options.mk,v 1.4 2019/02/08 13:09:35 fox Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ircd-hybrid
PKG_SUPPORTED_OPTIONS=	ssl
PKG_SUGGESTED_OPTIONS=	ssl

.include "../../mk/bsd.options.mk"

###
### Enable OpenSSL support
###
.if !empty(PKG_OPTIONS:Mssl)
.include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-openssl=${BUILDLINK_PREFIX.openssl}
.else
CONFIGURE_ARGS+=	--disable-openssl
.endif
