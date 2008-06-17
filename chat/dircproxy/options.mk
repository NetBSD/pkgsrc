# $NetBSD: options.mk,v 1.1 2008/06/17 12:53:54 tron Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.dircproxy
PKG_SUPPORTED_OPTIONS=	ssl debug
PKG_SUGGESTED_OPTIONS=	ssl

.include "../../mk/bsd.options.mk"

###
### Compile with SSL support
###
.if !empty(PKG_OPTIONS:Mssl)
CONFIGURE_ARGS+=	--enable-ssl
.include "../../security/openssl/buildlink3.mk"
.endif

###
### Turn on debugging
###
.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
.endif
