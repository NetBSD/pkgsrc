# $NetBSD: options.mk,v 1.9 2018/07/14 16:05:19 maya Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.vice
PKG_SUPPORTED_OPTIONS=		ffmpeg vte
PKG_OPTIONS_REQUIRED_GROUPS=	gui
PKG_OPTIONS_GROUP.gui=		gtk2 gtk3wip sdl xaw
PKG_SUGGESTED_OPTIONS=		gtk2

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	mo pcf sdl x11

# Cocoa user interface works only in application bundle.
#.if !empty(PKG_OPTIONS:Mcocoa)
#CONFIGURE_ARGS+=	--disable-bundle
#CONFIGURE_ARGS+=	--with-cocoa
#PLIST.x11=		yes
#INSTALL_TARGET=		bindist
#.else
USE_TOOLS+=		bdftopcf
#.endif

.if !empty(PKG_OPTIONS:Mgtk2)
CONFIGURE_ARGS+=	--enable-gnomeui
PLIST.mo=		yes
PLIST.pcf=		yes
PLIST.x11=		yes
.  include "../../x11/gtk2/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mgtk3wip)
CONFIGURE_ARGS+=	--enable-native-gtk3ui
PLIST.pcf=		yes
PLIST.x11=		yes
.  include "../../x11/gtk3/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Msdl)
CONFIGURE_ARGS+=	--enable-sdlui2
PLIST.sdl=		yes
.  include "../../devel/SDL2/buildlink3.mk"
.endif

# If desired, ffmpeg and lame can be build-time-only dependencies,
# since they are loaded dynamically only.
.if !empty(PKG_OPTIONS:Mffmpeg)
#BUILDLINK_DEPMETHOD.ffmpeg?=	build
CONFIGURE_ARGS+=	--enable-external-ffmpeg
.  include "../../multimedia/ffmpeg3/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mvte)
.  if !empty(PKG_OPTIONS:Mgtk2) || !empty(PKG_OPTIONS:Mgtk3wip)
.    include "../../x11/vte/buildlink3.mk"
.  else
#    vte only makes sense with gtk*
.  endif
.endif

.if !empty(PKG_OPTIONS:Mxaw)
PLIST.mo=		yes
PLIST.pcf=		yes
PLIST.x11=		yes
.  include "../../x11/libXt/buildlink3.mk"
.  include "../../x11/libXmu/buildlink3.mk"
.  include "../../x11/libXaw/buildlink3.mk"
.  include "../../x11/libXpm/buildlink3.mk"
.  include "../../x11/libXrandr/buildlink3.mk"
.  include "../../x11/libXv/buildlink3.mk"
.  include "../../x11/libXxf86vm/buildlink3.mk"
.endif
