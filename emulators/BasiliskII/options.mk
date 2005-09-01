# $NetBSD: options.mk,v 1.3 2005/09/01 11:31:57 hira Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.BasiliskII
PKG_SUPPORTED_OPTIONS=	esound gtk sdl
PKG_OPTIONS_LEGACY_OPTS+=	esd:esound

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mesound)
CONFIGURE_ARGS+=	--with-esd
.include "../../audio/esound/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-esd
.endif

.if !empty(PKG_OPTIONS:Mgtk)
CONFIGURE_ARGS+=	--with-gtk
.include "../../x11/gtk/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-gtk
.endif

.if !empty(PKG_OPTIONS:Msdl)
CONFIGURE_ARGS+=	--enable-sdl-audio
CONFIGURE_ARGS+=	--enable-sdl-video
.include "../../devel/SDL/buildlink3.mk"
.else
.include "../../mk/x11.buildlink3.mk"
.endif
