# $NetBSD: options.mk,v 1.1.1.1 2008/06/16 10:38:27 adrianp Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.atheme

PKG_SUPPORTED_OPTIONS=	ssl atheme-large-net
PKG_SUGGESTED_OPTIONS=	ssl

.include "../../mk/bsd.options.mk"

###
### Compile in OpenSSL support
###
.if !empty(PKG_OPTIONS:Mssl)
.  include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-ssl
.else
CONFIGURE_ARGS+=	--disable-ssl
.endif

###
### Large network support (i.e. > 2000 users)
###
.if !empty(PKG_OPTIONS:Matheme-large-net)
CONFIGURE_ARGS+=	--enable-large-net
.endif
