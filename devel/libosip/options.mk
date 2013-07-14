# $NetBSD: options.mk,v 1.1 2013/07/14 14:55:16 rodent Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libosip
PKG_SUPPORTED_OPTIONS=	debug
PKG_SUGGESTED_OPTIONS+=	# blank

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug --enable-trace
.else
CONFIGURE_ARGS+=	--disable-debug --disable-trace
.endif
