# $NetBSD: options.mk,v 1.8 2005/12/05 23:55:03 rillig Exp $

.include "../../mk/bsd.prefs.mk"


PKG_OPTIONS_VAR=	PKG_OPTIONS.xchat
PKG_SUPPORTED_OPTIONS=	inet6 ssl socks5
PKG_SUGGESTED_OPTIONS=	ssl

.include "../../mk/bsd.options.mk"

###
### Use OpenSSL libraries for connecting to ircs servers
###
.if !empty(PKG_OPTIONS:Mssl)
.	include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-openssl=${SSLBASE:Q}
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
