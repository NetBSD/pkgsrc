# $NetBSD: options.mk,v 1.1 2005/06/02 21:48:42 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.xchat
PKG_SUPPORTED_OPTIONS=	inet6 socks5 ssl
PKG_SUGGESTED_OPTIONS=	ssl
PKG_OPTIONS_LEGACY_VARS+=	XCHAT_USE_SSL:ssl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.if !empty(PKG_OPTIONS:Mssl)
.  include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-openssl=${SSLBASE}
.endif

.if !empty(PKG_OPTIONS:Msocks5)
CONFIGURE_ARGS+=	--enable-socks
.endif
