# $NetBSD: options.mk,v 1.1.1.1 2006/01/24 20:21:46 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.e-uae
PKG_SUPPORTED_OPTIONS=	gtk sdl x11
PKG_SUGGESTED_OPTIONS=	gtk sdl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgtk)
.include "../../x11/gtk2/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Msdl)
CONFIGURE_ARGS+=	--with-sdl --with-sdl-gfx
.include "../../devel/SDL/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mx11)
CONFIGURE_ARGS+=	--enable-dga --enable-vidmode
.include "../../mk/x11.buildlink3.mk"
.endif
