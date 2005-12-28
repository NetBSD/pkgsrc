# $NetBSD: options.mk,v 1.1.1.1 2005/12/28 15:49:41 ghen Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.netcat6
PKG_SUPPORTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

.if empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--disable-ipv6
.endif
