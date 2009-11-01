# $NetBSD: options.mk,v 1.5 2009/11/01 15:46:07 tnn Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.rocksndiamonds
PKG_SUPPORTED_OPTIONS=	sdl x11
PKG_SUGGESTED_OPTIONS=	sdl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msdl)
.  if ${OPSYS} == "Solaris"
BUILD_TARGET=	solaris-sdl
.  else
BUILD_TARGET=	sdl
.  endif
.  include "../../audio/SDL_mixer/buildlink3.mk"
.  include "../../graphics/SDL_image/buildlink3.mk"
.  include "../../multimedia/smpeg/buildlink3.mk"
.  include "../../net/SDL_net/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mx11)
.  if ${OPSYS} == "Solaris"
BUILD_TARGET=	solaris
.  else
BUILD_TARGET=	x11
.  endif
.  include "../../mk/oss.buildlink3.mk"
.  include "../../x11/libXt/buildlink3.mk"
.endif
