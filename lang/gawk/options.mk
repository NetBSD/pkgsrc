# $NetBSD: options.mk,v 1.1 2012/06/15 00:29:27 sbd Exp $

PKG_OPTIONS_VAR=        PKG_OPTIONS.gawk
PKG_SUPPORTED_OPTIONS=  portals

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mportals)
CONFIGURE_ARGS+=        --enable-portals
.endif
