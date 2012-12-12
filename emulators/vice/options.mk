# $NetBSD: options.mk,v 1.7 2012/12/12 09:58:03 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.vice
PKG_SUPPORTED_OPTIONS=	ffmpeg lame vice-fullscreen vice-hwscaling vice-ethernet
PKG_OPTIONS_REQUIRED_GROUPS = gui
PKG_OPTIONS_GROUP.gui = xaw gnome sdl
PKG_SUGGESTED_OPTIONS=	ffmpeg lame vice-fullscreen vice-hwscaling vice-ethernet
PKG_SUGGESTED_OPTIONS+=	xaw

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mxaw)
.  include "../../x11/libXt/buildlink3.mk"
.  include "../../x11/libXmu/buildlink3.mk"
.  include "../../x11/libXaw/buildlink3.mk"
.  include "../../x11/libXpm/buildlink3.mk"
PLIST_SRC += PLIST.x11
.endif

.if !empty(PKG_OPTIONS:Mgnome)
CONFIGURE_ARGS+=	--enable-gnomeui
PLIST_SRC+=		PLIST.x11
.  include "../../x11/gtk2/buildlink3.mk"
.  include "../../x11/vte/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Msdl)
CONFIGURE_ARGS+=	--enable-sdlui
PLIST_SRC+=		PLIST.sdl
.  include "../../devel/SDL/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mvice-fullscreen)
CONFIGURE_ARGS+=	--enable-fullscreen
.  if !empty(PKG_OPTIONS:Mxaw)
.    include "../../x11/libXrandr/buildlink3.mk"
.    include "../../x11/libXxf86vm/buildlink3.mk"
.  endif
.  if !empty(PKG_OPTIONS:Mgnome)
.    include "../../x11/libXrandr/buildlink3.mk"
.    include "../../x11/libXxf86vm/buildlink3.mk"
.  endif
.  if !empty(PKG_OPTIONS:Msdl)
.  endif
.endif

.if !empty(PKG_OPTIONS:Mvice-hwscaling)
.  if !empty(PKG_OPTIONS:Mxaw)
.    include "../../x11/libXv/buildlink3.mk"
.  endif
.  if !empty(PKG_OPTIONS:Mgnome)
.    include "../../graphics/gtkglext/buildlink3.mk"
.  endif
.  if !empty(PKG_OPTIONS:Msdl)
.  endif
.endif

.if !empty(PKG_OPTIONS:Mvice-ethernet)
CONFIGURE_ARGS+=	--enable-ethernet
.  include "../../net/libpcap/buildlink3.mk"
.endif

# If desired, ffmpeg and lame can be build-time-only dependencies,
# since they are loaded dynamically only.
.if !empty(PKG_OPTIONS:Mffmpeg)
#BUILDLINK_DEPMETHOD.ffmpeg?=	build
CONFIGURE_ARGS+=	--enable-ffmpeg
.  include "../../multimedia/ffmpeg010/buildlink3.mk"
.endif
.if !empty(PKG_OPTIONS:Mlame)
#BUILDLINK_DEPMETHOD.lame?=	build
.  include "../../audio/lame/buildlink3.mk"
.endif
