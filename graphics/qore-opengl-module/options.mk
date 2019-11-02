# $NetBSD: options.mk,v 1.2 2019/11/02 22:38:03 rillig Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.qore-opengl-module
PKG_SUPPORTED_OPTIONS=	debug
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
.else
CONFIGURE_ARGS+=	--disable-debug
.endif
