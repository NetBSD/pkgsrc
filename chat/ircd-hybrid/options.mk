# $NetBSD: options.mk,v 1.5 2020/01/23 10:06:22 fox Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ircd-hybrid
PKG_SUPPORTED_OPTIONS=	ssl
PKG_SUGGESTED_OPTIONS=	ssl

.include "../../mk/bsd.options.mk"

###
### Enable OpenSSL support
###
.if !empty(PKG_OPTIONS:Mssl)
.include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-tls=openssl
.else
CONFIGURE_ARGS+=	--with-tls=none
.endif
