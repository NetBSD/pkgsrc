# $NetBSD: options.mk,v 1.9 2024/04/02 20:34:16 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.BasiliskII
PKG_SUPPORTED_OPTIONS=		gtk2 sdl

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} != "Darwin"
PKG_SUGGESTED_OPTIONS+=		gtk2 sdl
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgtk2)
CONFIGURE_ARGS+=	--with-gtk
.include "../../x11/gtk2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-gtk
.endif

.if !empty(PKG_OPTIONS:Msdl)
CONFIGURE_ARGS+=	--enable-sdl-audio
CONFIGURE_ARGS+=	--enable-sdl-video
.include "../../devel/SDL/buildlink3.mk"
.elif ${OPSYS} == "Darwin"
CONFIGURE_ARGS+=	--enable-macosx-gui
CONFIGURE_ARGS+=	--enable-macosx-sound
.endif
