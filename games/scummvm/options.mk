# $NetBSD: options.mk,v 1.6 2007/02/02 17:58:02 joerg Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.scummvm
PKG_SUPPORTED_OPTIONS=	sdl x11
PKG_SUGGESTED_OPTIONS=	sdl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msdl)
CONFIGURE_ARGS+=	--backend=sdl
.include "../../devel/SDL/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mx11)
CONFIGURE_ARGS+=	--backend=x11
.include "../../mk/oss.buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.endif
