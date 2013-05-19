# $NetBSD: options.mk,v 1.6 2013/05/19 07:35:56 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.atari800
PKG_SUPPORTED_OPTIONS=	sdl x11
PKG_SUGGESTED_OPTIONS=	sdl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mx11)
CONFIGURE_ARGS+=	--target=x11
.include "../../x11/libX11/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Msdl)
CONFIGURE_ARGS+=	--target=default
CONFIGURE_ARGS+=	--with-video=sdl
.include "../../devel/SDL/buildlink3.mk"
.endif
