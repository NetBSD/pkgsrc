# $NetBSD: options.mk,v 1.2 2014/04/18 14:44:29 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.SDL2_ttf
PKG_SUPPORTED_OPTIONS=	static x11
PKG_SUGGESTED_OPTIONS+=	static

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mstatic)
CONFIGURE_ARGS+=	--enable-static=yes
.else
CONFIGURE_ARGS+=	--enable-static=no
.endif

.if !empty(PKG_OPTIONS:Mx11)
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.endif
