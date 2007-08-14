# $NetBSD: options.mk,v 1.1 2007/08/14 09:30:56 obache Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.vino
PKG_SUPPORTED_OPTIONS+=	inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif
