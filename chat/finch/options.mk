# $NetBSD: options.mk,v 1.6 2016/01/13 22:25:38 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.finch
PKG_SUPPORTED_OPTIONS+=		debug

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
.endif
