# $NetBSD: options.mk,v 1.3 2018/03/07 11:57:32 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.x2vnc

# Warning - breaks dragging on remote screens for some setups
PKG_SUPPORTED_OPTIONS=	dga
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdga)
. include "../../x11/libXxf86dga/buildlink3.mk"
. include "../../x11/xorgproto/buildlink3.mk"
.endif
