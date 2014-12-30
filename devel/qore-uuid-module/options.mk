# $NetBSD: options.mk,v 1.1 2014/12/30 15:54:32 wiz Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.qore-uuid-module
PKG_SUPPORTED_OPTIONS=	debug
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=        --enable-debug
.else
CONFIGURE_ARGS+=        --disable-debug
.endif
