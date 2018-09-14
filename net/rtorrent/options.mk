# $NetBSD: options.mk,v 1.3 2018/09/14 21:06:42 maya Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.rtorrent
PKG_SUPPORTED_OPTIONS=	xmlrpc
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mxmlrpc)
CONFIGURE_ARGS+=       --with-xmlrpc-c=${PREFIX}/bin/xmlrpc-c-config
.  include "../../textproc/xmlrpc-c/buildlink3.mk"
.endif
