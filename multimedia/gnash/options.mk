# $NetBSD: options.mk,v 1.16 2011/12/08 10:39:13 obache Exp $
#

#
# see http://www.gnu.org/software/gnash/manual/gnashref.html#codedeps
#

PKG_OPTIONS_VAR=		PKG_OPTIONS.gnash
PKG_OPTIONS_OPTIONAL_GROUPS=	gnash-media
PKG_OPTIONS_GROUP.gnash-media=	ffmpeg gstreamer
PKG_OPTIONS_REQUIRED_GROUPS=	gnash-gui gnash-renderer
# XXX: add support for SDL or FLTK GUIs?
PKG_OPTIONS_GROUP.gnash-gui=	gtk kde kde3
PKG_OPTIONS_GROUP.gnash-renderer=	agg cairo opengl
PKG_SUGGESTED_OPTIONS+=		agg gstreamer gtk

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	gtk kde kde3 kde4 plugin gstreamer

###
### Select GUIs.
###
.if !empty(PKG_OPTIONS:Mgtk)
GNASH_GUIS+=		gtk
PLIST.gtk=		yes
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mgtk) || !empty(PKG_OPTIONS:Mkde)
BUILDLINK_DEPMETHOD.xulrunner192=	build
.include "../../devel/xulrunner192/buildlink3.mk"
CONFIGURE_ARGS+=	--with-npapi-incl=${BUILDLINK_PREFIX.xulrunner192}/include/xulrunner192
CONFIGURE_ARGS+=	--with-npapi-install=system
CONFIGURE_ARGS+=	--with-npapi-plugindir=${PREFIX}/lib/netscape/plugins
PLIST.plugin=		yes
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.endif

.if !empty(PKG_OPTIONS:Mkde)
GNASH_GUIS+=		kde4
PLIST.kde=		yes
PLIST.kde4=		yes
CONFIGURE_ARGS+=	--with-plugins-install=system
# broken, not wroked as expected.
#CONFIGURE_ARGS+=	--with-kde4-plugindir=${PREFIX}/lib/kde4
#CONFIGURE_ARGS+=	--with-kde-appsdatadir=${PREFIX}/share/kde/apps
#CONFIGURE_ARGS+=	--with-kde4-configdir=${PREFIX}/share/kde4/config
#CONFIGURE_ARGS+=	--with-kde4-servicesdir=${PREFIX}/share/kde4/services
.include "../../x11/kdebase4/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../meta-pkgs/kde4/kde4.mk"

.elif !empty(PKG_OPTIONS:Mkde3)
GNASH_GUIS+=		kde3
PLIST.kde=		yes
PLIST.kde3=		yes
CONFIGURE_ARGS+=	--with-plugins-install=system
# broken, not wroked as expected.
#CONFIGURE_ARGS+=	--with-kde3-plugindir=${PREFIX}/lib/kde3
#CONFIGURE_ARGS+=	--with-kde-appsdatadir=${PREFIX}/share/kde/apps
#CONFIGURE_ARGS+=	--with-kde3-configdir=${PREFIX}/share/kde/config
#CONFIGURE_ARGS+=	--with-kde3-servicesdir=${PREFIX}/share/kde/services
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../meta-pkgs/kde3/kde3.mk"
# overwrite, or not kde ralated files also will be installed in share/kde.
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share
.endif

CONFIGURE_ARGS+=	--enable-gui=${GNASH_GUIS:tW:S/ /,/}

###
### Select renderers.
###
.if !empty(PKG_OPTIONS:Magg)
GNASH_RENDER+=		agg
.include "../../graphics/agg/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mcairo)
GNASH_RENDER+=		cairo
.include "../../graphics/cairo/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mopengl)
GNASH_RENDER+=		ogl
.include "../../x11/glproto/buildlink3.mk"
.  if !empty(PKG_OPTIONS:Mgtk)
.include "../../graphics/gtkglext/buildlink3.mk"
.  endif
.endif

CONFIGURE_ARGS+=	--enable-renderer=${GNASH_RENDER:tW:S/ /,/}

###
### Select a media handler
###
.if !empty(PKG_OPTIONS:Mffmpeg)
GNASH_MEDIA+=	ffmpeg
.include "../../audio/libdca/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../multimedia/ffmpeg/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mgstreamer)
GNASH_MEDIA+=	gst
PLIST.gstreamer=	yes
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
DEPENDS+= gst-ffmpeg-0.10.[0-9]*:../../multimedia/gst-plugins0.10-ffmpeg
DEPENDS+= gst-plugins0.10-mad-[0-9]*:../../audio/gst-plugins0.10-mad
DEPENDS+= gst-plugins0.10-vorbis-[0-9]*:../../audio/gst-plugins0.10-vorbis
.endif

CONFIGURE_ARGS+=	--enable-media=${GNASH_MEDIA:Unone:tW:S/ /,/}

.if !empty(PKG_OPTIONS:Mffmpeg)
.include "../../multimedia/ffmpeg/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-hwaccel=VAAPI
.else
CONFIGURE_ARGS+=	--enable-hwaccel=none
.endif
