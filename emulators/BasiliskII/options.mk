# $NetBSD: options.mk,v 1.7 2019/07/30 08:08:22 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.BasiliskII
PKG_SUPPORTED_OPTIONS=		esound gtk2 sdl
PKG_OPTIONS_LEGACY_OPTS+=	esd:esound

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} != "Darwin"
PKG_SUGGESTED_OPTIONS+=		gtk2 sdl
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mesound)
CONFIGURE_ARGS+=	--with-esd
.include "../../audio/esound/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-esd
.endif

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
.endif
