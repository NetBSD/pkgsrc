# $NetBSD: options.mk,v 1.2 2019/11/02 15:38:10 rillig Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.qore-sqlite3-module
PKG_SUPPORTED_OPTIONS=	debug
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
.else
CONFIGURE_ARGS+=	--disable-debug
.endif
