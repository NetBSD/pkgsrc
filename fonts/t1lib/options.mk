# $NetBSD: options.mk,v 1.4 2021/03/21 00:01:46 rillig Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.t1lib
PKG_SUPPORTED_OPTIONS+=	x11
PKG_SUGGESTED_OPTIONS+=	x11

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mx11)
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/xaw.buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.endif
