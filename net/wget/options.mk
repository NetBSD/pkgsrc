# $NetBSD: options.mk,v 1.1 2005/02/09 17:51:47 tv Exp $

# Global and legacy options
.if defined(WGET_USE_SSL)
BUILD_DEFS+=		WGET_USE_SSL
.  if !empty(WGET_USE_SSL:M[Yy][Ee][Ss])
PKG_DEFAULT_OPTIONS+=	ssl
.  endif
.else
PKG_DEFAULT_OPTIONS+=	ssl # on by default
.endif

PKG_OPTIONS_VAR=	PKG_OPTIONS.wget
PKG_SUPPORTED_OPTIONS=	inet6 ssl
.include "../../mk/bsd.options.mk"

###
### Support IPv6
###
.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

###
### Support SSL
###
.if !empty(PKG_OPTIONS:Mssl)
.  include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=--with-ssl=${SSLBASE}
.else
CONFIGURE_ARGS+=--without-ssl
.endif
