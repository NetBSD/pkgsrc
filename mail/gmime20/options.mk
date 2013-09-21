# $NetBSD: options.mk,v 1.1 2013/09/21 13:21:29 obache Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gmime20
PKG_SUPPORTED_OPTIONS=	inet6
PKG_SUGGESTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif
