# $NetBSD: options.mk,v 1.2 2015/04/23 09:17:48 abs Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.x2vnc

# Warning - breaks dragging on remote screens for some setups
PKG_SUPPORTED_OPTIONS=	dga
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdga)
. include "../../x11/libXxf86dga/buildlink3.mk"
. include "../../x11/xf86dgaproto/buildlink3.mk"
.endif
