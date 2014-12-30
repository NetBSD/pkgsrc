# $NetBSD: options.mk,v 1.1 2014/12/30 15:57:09 wiz Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.qore-opengl-module
PKG_SUPPORTED_OPTIONS=	debug
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=        --enable-debug
.else
CONFIGURE_ARGS+=        --disable-debug
.endif
