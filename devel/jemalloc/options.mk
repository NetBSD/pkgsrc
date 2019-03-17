# $NetBSD: options.mk,v 1.1 2019/03/17 13:28:22 rin Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.jemalloc
PKG_SUPPORTED_OPTIONS=		debug

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
.endif
