# $NetBSD: options.mk,v 1.1 2008/07/30 09:53:36 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.liboil
PKG_SUPPORTED_OPTIONS=	debug

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
.endif
