# $NetBSD: options.mk,v 1.4 2005/06/06 12:02:08 tron Exp $

.include "../../mk/bsd.prefs.mk"

.if defined(PKG_OPTIONS.xchat2)
PKG_OPTIONS.xchat?=	${PKG_OPTIONS.xchat2}
.endif

PKG_OPTIONS_VAR=	PKG_OPTIONS.xchat
PKG_SUPPORTED_OPTIONS=	inet6 ssl socks5
PKG_SUGGESTED_OPTIONS=	inet6 ssl
PKG_OPTIONS_LEGACY_OPTS+=	socks:socks5

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
.if !empty(PKG_OPTIONS:Msocks5)
CONFIGURE_ARGS+=	--enable-socks
.endif

###
### IPv6 support.
###
.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif
