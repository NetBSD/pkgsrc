# $NetBSD: options.mk,v 1.8 2015/10/14 20:17:25 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.freeciv-client
PKG_OPTIONS_REQUIRED_GROUPS=	backend
#PKG_OPTIONS_GROUP.backend=	gtk2 gtk3 qt5 sdl xaw xaw3d
PKG_OPTIONS_GROUP.backend=	gtk2 gtk3 sdl xaw xaw3d
PKG_SUGGESTED_OPTIONS=		gtk2

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgtk2)
CONFIGURE_ARGS+=	--enable-client=gtk2
CONFIGURE_ARGS+=	--enable-fcmp=gtk2
.include "../../x11/gtk2/buildlink3.mk"
PLIST_SRC=		${PKGDIR}/PLIST.gtk2
.endif

.if !empty(PKG_OPTIONS:Mgtk3)
CONFIGURE_ARGS+=	--enable-client=gtk3
CONFIGURE_ARGS+=	--enable-fcmp=gtk3
.include "../../x11/gtk3/buildlink3.mk"
PLIST_SRC=		${PKGDIR}/PLIST.gtk3
.endif

.if !empty(PKG_OPTIONS:Mqt5)
CONFIGURE_ARGS+=	--enable-client=qt
CONFIGURE_ARGS+=	--enable-fcmp=qt
.include "../../x11/qt5-qtbase/buildlink3.mk"
PLIST_SRC=		${PKGDIR}/PLIST.qt
.endif

.if !empty(PKG_OPTIONS:Msdl)
CONFIGURE_ARGS+=	--enable-client=sdl
CONFIGURE_ARGS+=	--enable-fcmp=cli
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../devel/SDL_gfx/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
PLIST_SRC=		${PKGDIR}/PLIST.sdl
.endif

.if !empty(PKG_OPTIONS:Mxaw)
CONFIGURE_ARGS+=	--enable-client=xaw
CONFIGURE_ARGS+=	--enable-fcmp=cli
CONFIGURE_ARGS+=	--with-xaw
.include "../../mk/xaw.buildlink3.mk"
PLIST_SRC=		${PKGDIR}/PLIST.xaw
.endif

.if !empty(PKG_OPTIONS:Mxaw3d)
CONFIGURE_ARGS+=	--enable-client=xaw
CONFIGURE_ARGS+=	--enable-fcmp=cli
CONFIGURE_ARGS+=	--with-xaw3d
.include "../../x11/libXaw3d/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
PLIST_SRC=		${PKGDIR}/PLIST.xaw
.endif
