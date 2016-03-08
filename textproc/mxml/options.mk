# $NetBSD: options.mk,v 1.1 2016/03/08 13:52:36 nros Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mxml
PKG_SUPPORTED_OPTIONS=	debug
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=        --enable-debug=yes
.endif
