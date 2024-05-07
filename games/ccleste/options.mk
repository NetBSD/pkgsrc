# $NetBSD: options.mk,v 1.1 2024/05/07 08:40:19 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.ccleste

PKG_OPTIONS_GROUP.sdl=		sdl sdl2
PKG_OPTIONS_REQUIRED_GROUPS+=	sdl

.include "../../mk/bsd.fast.prefs.mk"

.if ${MACHINE_PLATFORM:MDarwin-*-powerpc*}
PKG_SUGGESTED_OPTIONS=		sdl
.else
PKG_SUGGESTED_OPTIONS=		sdl2
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msdl2)
MAKE_FLAGS+=	SDL_VER=2
.  include "../../audio/SDL2_mixer/buildlink3.mk"
.  include "../../devel/SDL2/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Msdl)
MAKE_FLAGS+=	SDL_VER=1
.  include "../../audio/SDL_mixer/buildlink3.mk"
.  include "../../devel/SDL/buildlink3.mk"
.endif
