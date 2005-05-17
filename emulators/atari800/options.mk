# $NetBSD: options.mk,v 1.2 2005/05/17 15:08:57 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.atari800
PKG_DEFAULT_OPTIONS=	sdl
PKG_SUPPORTED_OPTIONS=	sdl x11

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mx11)
USE_X11=		yes
CONFIGURE_ARGS+=	--target=x11
.endif

.if !empty(PKG_OPTIONS:Msdl)
CONFIGURE_ARGS+=	--target=sdl
.include "../../devel/SDL/buildlink3.mk"
.endif
