# $NetBSD: options.mk,v 1.2 2020/05/31 15:34:32 rillig Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libosip
PKG_SUPPORTED_OPTIONS=	debug
PKG_SUGGESTED_OPTIONS=	# none

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-trace
.else
CONFIGURE_ARGS+=	--disable-trace
.endif
