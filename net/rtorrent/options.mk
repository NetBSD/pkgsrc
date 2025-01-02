# $NetBSD: options.mk,v 1.4 2025/01/02 20:00:05 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.rtorrent
PKG_SUPPORTED_OPTIONS=	xmlrpc

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mxmlrpc)
CONFIGURE_ARGS+=       --with-xmlrpc-tinyxml2
.  include "../../textproc/tinyxml2/buildlink3.mk"
.endif
