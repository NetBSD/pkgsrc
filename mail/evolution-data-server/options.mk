# $NetBSD: options.mk,v 1.1 2009/05/28 20:25:25 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.evolution-data-server
PKG_SUPPORTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif
