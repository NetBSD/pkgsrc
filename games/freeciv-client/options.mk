# $NetBSD: options.mk,v 1.10 2019/08/31 14:44:57 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.freeciv-client
PKG_OPTIONS_REQUIRED_GROUPS=	backend
PKG_OPTIONS_GROUP.backend=	gtk3 sdl
PKG_SUGGESTED_OPTIONS=		gtk3

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgtk3)
CONFIGURE_ARGS+=	--enable-client=gtk3
CONFIGURE_ARGS+=	--enable-fcmp=gtk3
.include "../../x11/gtk3/buildlink3.mk"
PLIST_SRC=		${PKGDIR}/PLIST.gtk3
.endif

.if !empty(PKG_OPTIONS:Msdl)
CONFIGURE_ARGS+=	--enable-client=sdl
CONFIGURE_ARGS+=	--enable-fcmp=cli
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../devel/SDL_gfx/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
PLIST_SRC=		${PKGDIR}/PLIST.sdl
.endif
