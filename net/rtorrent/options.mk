# $NetBSD: options.mk,v 1.2 2018/06/24 16:59:52 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.rtorrent
PKG_SUPPORTED_OPTIONS=	xmlrpc
PKG_SUGGESTED_OPTIONS=	xmlrpc

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mxmlrpc)
CONFIGURE_ARGS+=       --with-xmlrpc-c=${PREFIX}/bin/xmlrpc-c-config
.  include "../../textproc/xmlrpc-c/buildlink3.mk"
.endif
