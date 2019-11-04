# $NetBSD: options.mk,v 1.2 2019/11/04 21:43:39 rillig Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mxml
PKG_SUPPORTED_OPTIONS=	debug
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug=yes
.endif
