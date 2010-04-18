# $NetBSD: options.mk,v 1.1 2010/04/18 18:22:43 jmmv Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gamin
PKG_SUPPORTED_OPTIONS=	debug

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
CONFIGURE_ARGS+=	--enable-debug-api
.endif
