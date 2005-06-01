# $NetBSD: options.mk,v 1.1 2005/06/01 14:47:54 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.evolution14
PKG_SUPPORTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6=yes
.else
CONFIGURE_ARGS+=	--enable-ipv6=no
.endif
