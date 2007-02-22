# $NetBSD: options.mk,v 1.2 2007/02/22 19:26:12 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ninja
PKG_SUPPORTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif
