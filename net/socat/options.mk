# $NetBSD: options.mk,v 1.1 2007/10/09 20:21:29 adrianp Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.socat
PKG_SUPPORTED_OPTIONS+=	inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ip6
.else
CONFIGURE_ARGS+=	--disable-ip6
.endif
