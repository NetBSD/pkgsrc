# $NetBSD: options.mk,v 1.1 2004/10/30 18:28:00 minskim Exp $

# Global and legacy options
.if defined(USE_SOCKS) && !empty(USE_SOCKS:M[Yy][Ee][Ss])
PKG_DEFAULT_OPTIONS+=	socks
.endif
.if defined(XCHAT_USE_SSL) && !empty(XCHAT_USE_SSL:M[Yy][Ee][Ss])
PKG_DEFAULT_OPTIONS+=	ssl
.endif
.if defined(USE_INET6) && !empty(USE_INET6:M[yY][eE][sS])
PKG_DEFAULT_OPTIONS+=	inet6
.endif

PKG_OPTIONS_VAR=	PKG_OPTIONS.xchat2
PKG_SUPPORTED_OPTIONS=	inet6 ssl socks

.if !defined(PKG_OPTIONS.xchat2)
PKG_DEFAULT_OPTIONS+=	inet6 ssl
.endif

.include "../../mk/bsd.options.mk"

###
### Use OpenSSL libraries for connecting to ircs servers
###
.if !empty(PKG_OPTIONS:Mssl)
.	include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-openssl=${SSLBASE}
.else
CONFIGURE_ARGS+=	--enable-openssl=no
.endif

###
### Support for connecting thru SOCKS servers
###
.if !empty(PKG_OPTIONS:Msocks)
CONFIGURE_ARGS+=	--enable-socks
.endif

###
### IPv6 support.
###
.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif
