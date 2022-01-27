# $NetBSD: options.mk,v 1.15 2022/01/27 18:23:39 rhialto Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.vice
PKG_SUPPORTED_OPTIONS=		ffmpeg vice-x64 vice-cpuhistory pulseaudio alsa
PKG_OPTIONS_REQUIRED_GROUPS=	gui
PKG_OPTIONS_GROUP.gui=		gtk3 sdl sdl2 vice-headless
PKG_SUGGESTED_OPTIONS=		gtk3 ffmpeg

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	gtk sdl x64 desktop gh

.if !empty(PKG_OPTIONS:Mgtk3)
CONFIGURE_ARGS+=	--enable-native-gtk3ui
PLIST.gtk=		yes
PLIST.gh=		yes	# gtk-or-headless
TOOL_DEPENDS+=		glib2-tools>=2.56:../../devel/glib2-tools

CONFIGURE_ARGS+=	--enable-desktop-files
PLIST.desktop=		yes
TOOL_DEPENDS+=		xdg-utils-[0-9]*:../../misc/xdg-utils

.  include "../../x11/gtk3/buildlink3.mk"
.  include "../../graphics/glew/buildlink3.mk"

# XXX work around misc/xdg-utils being completely broken;
#     the post-install target moves the *.menu file around.
XDG_CONFIG_DIR=		${PREFIX}/etc/xdg
XDG_DATA_DIR=		${PREFIX}/share
MAKE_ENV+=		XDG_CONFIG_DIRS="${DESTDIR}${XDG_CONFIG_DIR}"
MAKE_ENV+=		XDG_DATA_DIRS="${DESTDIR}${XDG_DATA_DIR}"
MAKE_ENV+=		XDG_UTILS_DEBUG_LEVEL=999
INSTALLATION_DIRS+=	${XDG_CONFIG_DIR}/menus/applications-merged
INSTALLATION_DIRS+=	${XDG_DATA_DIR}/applications
INSTALLATION_DIRS+=	${XDG_DATA_DIR}/desktop-directories
MAKE_DIRS+=		${PKG_SYSCONFBASE}/xdg/menus/applications-merged

CONF_FILES+=	${PREFIX}/share/vice/vice-org-vice-org.menu \
		${PKG_SYSCONFBASE}/xdg/menus/applications-merged/vice-org-vice-org.menu

BUILD_DEFS+=	PKG_SYSCONFBASE

.  include "../../sysutils/desktop-file-utils/desktopdb.mk"
.endif

.if !empty(PKG_OPTIONS:Msdl)
CONFIGURE_ARGS+=	--enable-sdlui
PLIST.sdl=		yes
.  include "../../devel/SDL/buildlink3.mk"
.  include "../../graphics/SDL_image/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Msdl2)
CONFIGURE_ARGS+=	--enable-sdlui2
PLIST.sdl=		yes
.  include "../../devel/SDL2/buildlink3.mk"
.  include "../../graphics/SDL2_image/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mvice-headless)
CONFIGURE_ARGS+=	--enable-headlessui
PLIST.gh=		yes	# gtk-or-headless
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

.if !empty(PKG_OPTIONS:Mpulseaudio)
CONFIGURE_ARGS+=	--with-pulse
.include "../../audio/pulseaudio/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-pulse
.endif

.if !empty(PKG_OPTIONS:Malsa)
CONFIGURE_ARGS+=	--with-alsa
#.include "../../audio/alsa/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-alsa
.endif
