# $NetBSD: options.mk,v 1.6 2009/01/17 22:09:39 shattered Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.freeciv-client
PKG_OPTIONS_REQUIRED_GROUPS=	backend
PKG_OPTIONS_GROUP.backend=	gtk2 xaw xaw3d sdl
PKG_SUGGESTED_OPTIONS=		gtk2

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgtk2)
CONFIGURE_ARGS+=	--enable-client=gtk2
.include "../../x11/gtk2/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mxaw)
CONFIGURE_ARGS+=	--enable-client=xaw
.include "../../mk/xaw.buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mxaw3d)
CONFIGURE_ARGS+=	--enable-client=xaw3d
.include "../../x11/Xaw3d/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Msdl)
CONFIGURE_ARGS+=	--enable-client=sdl
#CONFIGURE_ARGS+=	--enable-ftwl=sdl
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.endif
