# $NetBSD: options.mk,v 1.1 2012/04/13 23:38:34 obache Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libupnp
PKG_SUPPORTED_OPTIONS=	inet6 debug
PKG_SUGGESTED_OPTIONS=	# empty

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
