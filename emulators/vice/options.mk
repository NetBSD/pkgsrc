# $NetBSD: options.mk,v 1.13 2020/04/23 17:45:26 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.vice
PKG_SUPPORTED_OPTIONS=		ffmpeg vice-x64 vice-cpuhistory
PKG_OPTIONS_REQUIRED_GROUPS=	gui
PKG_OPTIONS_GROUP.gui=		gtk3 sdl sdl2
PKG_SUGGESTED_OPTIONS=		gtk3 ffmpeg

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	gtk sdl x64

.if !empty(PKG_OPTIONS:Mgtk3)
CONFIGURE_ARGS+=	--enable-native-gtk3ui
PLIST.gtk=		yes
.  include "../../x11/gtk3/buildlink3.mk"
TOOL_DEPENDS+=		glib2-tools>=2.56:../../devel/glib2-tools
.  include "../../graphics/glew/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Msdl)
CONFIGURE_ARGS+=	--enable-sdlui
PLIST.sdl=		yes
.  include "../../devel/SDL/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Msdl2)
CONFIGURE_ARGS+=	--enable-sdlui2
PLIST.sdl=		yes
.  include "../../devel/SDL2/buildlink3.mk"
.endif

# If desired, ffmpeg and lame can be build-time-only dependencies,
# since they are loaded dynamically only.
.if !empty(PKG_OPTIONS:Mffmpeg)
#BUILDLINK_DEPMETHOD.ffmpeg?=	build
CONFIGURE_ARGS+=	--enable-external-ffmpeg
.  include "../../multimedia/ffmpeg4/buildlink3.mk"
.endif

# Building x64 is deprecated, in favour of x64sc (but that is slower).
.if !empty(PKG_OPTIONS:Mvice-x64)
CONFIGURE_ARGS+=	--enable-x64
PLIST.x64=		yes
.endif

.if !empty(PKG_OPTIONS:Mvice-cpuhistory)
CONFIGURE_ARGS+=	--enable-cpuhistory
.endif
