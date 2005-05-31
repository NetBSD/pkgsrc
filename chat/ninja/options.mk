# $NetBSD: options.mk,v 1.1 2005/05/31 22:00:37 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ninja
PKG_SUPPORTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=        --enable-ipv6
.endif
