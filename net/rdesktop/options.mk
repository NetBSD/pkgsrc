# $NetBSD: options.mk,v 1.2 2008/09/12 16:00:56 sborrill Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.rdesktop
PKG_SUPPORTED_OPTIONS+=	inet6 ssl
PKG_SUGGESTED_OPTIONS+=	inet6 ssl

.include "../../mk/bsd.options.mk"

###
### Support both IPv6 and IPv4 connections.
###
.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGE+=	--with-ipv6
.endif

.if !empty(PKG_OPTIONS:Mssl)
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE}
.include "../../security/openssl/buildlink3.mk"
.endif
