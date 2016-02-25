# $NetBSD: options.mk,v 1.6 2016/02/25 13:15:15 jperkin Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.rocksndiamonds
PKG_SUPPORTED_OPTIONS=	sdl x11
PKG_SUGGESTED_OPTIONS=	sdl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msdl)
BUILD_TARGET=	sdl
.  include "../../audio/SDL_mixer/buildlink3.mk"
.  include "../../graphics/SDL_image/buildlink3.mk"
.  include "../../multimedia/smpeg/buildlink3.mk"
.  include "../../net/SDL_net/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mx11)
BUILD_TARGET=	x11
.  include "../../mk/oss.buildlink3.mk"
.  include "../../x11/libXt/buildlink3.mk"
.endif
