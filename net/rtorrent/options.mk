# $NetBSD: options.mk,v 1.2.2.1 2018/09/15 12:25:47 bsiegert Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.rtorrent
PKG_SUPPORTED_OPTIONS=	xmlrpc
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mxmlrpc)
CONFIGURE_ARGS+=       --with-xmlrpc-c=${PREFIX}/bin/xmlrpc-c-config
.  include "../../textproc/xmlrpc-c/buildlink3.mk"
.endif
