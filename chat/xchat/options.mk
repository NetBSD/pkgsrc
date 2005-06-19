# $NetBSD: options.mk,v 1.6 2005/06/19 01:46:35 salo Exp $

.include "../../mk/bsd.prefs.mk"


PKG_OPTIONS_VAR=	PKG_OPTIONS.xchat
PKG_SUPPORTED_OPTIONS=	inet6 ssl socks5
PKG_SUGGESTED_OPTIONS=	ssl
PKG_OPTIONS_LEGACY_OPTS+=	socks:socks5

.if defined(PKG_OPTIONS.xchat2)
PKG_LEGACY_OPTIONS+=	${PKG_OPTIONS.xchat2}
PKG_OPTIONS_DEPRECATED_WARNINGS+="Deprecated variable PKG_OPTIONS.xchat2 used, use "${PKG_OPTIONS_VAR:Q}" instead."
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
.if !empty(PKG_OPTIONS:Msocks5)
CONFIGURE_ARGS+=	--enable-socks
.endif

###
### IPv6 support.
###
.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif
