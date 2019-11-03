# $NetBSD: options.mk,v 1.2 2019/11/03 11:45:41 rillig Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.maradns
PKG_SUPPORTED_OPTIONS+=	inet6
PKG_SUGGESTED_OPTIONS+=	inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--ipv6
.endif
