# $NetBSD: options.mk,v 1.1 2022/07/15 12:37:55 micha Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.leafnode
PKG_SUPPORTED_OPTIONS=	inet6
PKG_SUGGESTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--with-ipv6
.else
CONFIGURE_ARGS+=	--without-ipv6
.endif
