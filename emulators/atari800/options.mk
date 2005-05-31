# $NetBSD: options.mk,v 1.3 2005/05/31 10:01:36 dillo Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.atari800
PKG_SUPPORTED_OPTIONS=	sdl x11
PKG_SUGGESTED_OPTIONS=	sdl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mx11)
USE_X11=		yes
CONFIGURE_ARGS+=	--target=x11
.endif

.if !empty(PKG_OPTIONS:Msdl)
CONFIGURE_ARGS+=	--target=sdl
.include "../../devel/SDL/buildlink3.mk"
.endif
