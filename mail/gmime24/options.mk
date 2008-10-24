# $NetBSD: options.mk,v 1.1.1.1 2008/10/24 16:37:49 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gmime24
PKG_SUPPORTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif
