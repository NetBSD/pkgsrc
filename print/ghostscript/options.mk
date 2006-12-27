# $NetBSD: options.mk,v 1.2 2006/12/27 18:18:22 joerg Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ghostscript
PKG_SUPPORTED_OPTIONS=	x11
PKG_SUGGESTED_OPTIONS=	x11

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mx11)
CONFIGURE_ARGS+=	--with-x
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.else
CONFIGURE_ARGS+=        --without-x
.endif
