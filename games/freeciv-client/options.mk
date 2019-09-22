# $NetBSD: options.mk,v 1.11 2019/09/22 18:03:53 prlw1 Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.freeciv-client
PKG_OPTIONS_REQUIRED_GROUPS=	backend
PKG_OPTIONS_GROUP.backend=	gtk3 sdl
PKG_SUGGESTED_OPTIONS=		gtk3

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgtk3)
CONFIGURE_ARGS+=	--enable-client=gtk3.22
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
