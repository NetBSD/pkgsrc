# $NetBSD: options.mk,v 1.1 2009/04/17 16:19:27 abs Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.x2vnc

PKG_SUPPORTED_OPTIONS=	dga
PKG_SUGGESTED_OPTIONS=	dga

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdga)
. include "../../x11/libXxf86dga/buildlink3.mk"
. include "../../x11/xf86dgaproto/buildlink3.mk"
.endif
