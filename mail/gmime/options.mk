# $NetBSD: options.mk,v 1.2 2005/01/10 20:59:43 adrianp Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gmime
PKG_SUPPORTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif
