# $NetBSD: options.mk,v 1.8 2017/08/16 17:54:09 adam Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.vice
PKG_SUPPORTED_OPTIONS=		ffmpeg vte
PKG_OPTIONS_REQUIRED_GROUPS=	gui
PKG_OPTIONS_GROUP.gui=		gtk2 gtk3 sdl xaw
PKG_SUGGESTED_OPTIONS=		gtk3

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	pcf sdl x11

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
PLIST.pcf=		yes
PLIST.x11=		yes
.  include "../../x11/gtk2/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mgtk3)
CONFIGURE_ARGS+=	--enable-gnomeui3
PLIST.pcf=		yes
PLIST.x11=		yes
.  include "../../x11/gtk3/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Msdl)
CONFIGURE_ARGS+=	--enable-sdlui2
PLIST.pcf=		yes
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
.  include "../../x11/vte/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mxaw)
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
