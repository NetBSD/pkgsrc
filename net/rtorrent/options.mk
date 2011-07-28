# $NetBSD: options.mk,v 1.1 2011/07/28 23:14:46 tron Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.rtorrent
PKG_SUPPORTED_OPTIONS=	xmlrpc
PKG_SUGGESTED_OPTIONS=	xmlrpc

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mxmlrpc)
CONFIGURE_ARGS+=       --with-xmlrpc-c=${PREFIX:Q}/bin/xmlrpc-c-config
.  include "../../textproc/xmlrpc-c/buildlink3.mk"
.endif
