# $NetBSD: options.mk,v 1.1 2005/03/29 08:48:31 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.scummvm
PKG_DEFAULT_OPTIONS=	sdl
PKG_SUPPORTED_OPTIONS=	sdl x11

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msdl)
CONFIGURE_ARGS+=	--backend=sdl
.include "../../devel/SDL/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mx11)
CONFIGURE_ARGS+=	--backend=x11
.include "../../mk/ossaudio.buildlink3.mk"
.endif
