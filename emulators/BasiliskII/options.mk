# $NetBSD: options.mk,v 1.6 2012/10/23 10:24:03 wiz Exp $

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
BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXxf86dga/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.endif
