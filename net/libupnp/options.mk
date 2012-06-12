# $NetBSD: options.mk,v 1.2 2012/06/12 15:46:00 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libupnp
PKG_SUPPORTED_OPTIONS=	inet6 debug
PKG_SUGGESTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
.else
CONFIGURE_ARGS+=	--disable-debug
.endif
