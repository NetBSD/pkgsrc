# $NetBSD: options.mk,v 1.6 2008/04/29 20:16:08 wiz Exp $
#

#
# see http://www.gnu.org/software/gnash/manual/gnashref.html#codedeps
#

PKG_OPTIONS_VAR=		PKG_OPTIONS.gnash
PKG_SUPPORTED_OPTIONS=		gtk kde agg cairo mitshm opengl
PKG_OPTIONS_OPTIONAL_GROUPS=    gnash-media
PKG_OPTIONS_GROUP.gnash-media=  ffmpeg gstreamer
PKG_SUGGESTED_OPTIONS+=         agg gstreamer gtk mitshm

.include "../../mk/bsd.options.mk"

###
### Select GUIs.
###
.if !empty(PKG_OPTIONS:Mgtk)
GNASH_GUIS+=		gtk
PLIST_SRC+=		${PKGDIR}/PLIST.gtk
CONFIGURE_ARGS+=	--with-npapi-plugindir=${PREFIX}/lib/firefox/plugins
INSTALL_TARGET+=	install-plugin
.include "../../x11/gtk2/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mkde)
GNASH_GUIS+=		kde
PLIST_SRC+=		${PKGDIR}/PLIST.kde
PLIST_SUBST+=		KDE="kde/"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../meta-pkgs/kde3/kde3.mk"

post-install:
	cd ${WRKSRC}/plugin/klash && make install-plugin
.else
PLIST_SUBST+=		KDE=""
.endif

CONFIGURE_ARGS+=	--enable-gui=${GNASH_GUIS:tW:S/ /,/}

###
### Select renderers.
###
.if !empty(PKG_OPTIONS:Magg)
GNASH_RENDERS+=		agg
.include "../../graphics/agg/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mcairo)
GNASH_RENDERS+=		cairo
.include "../../graphics/cairo/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mopengl)
GNASH_RENDERS+=		ogl
.include "../../x11/glproto/buildlink3.mk"
.if !empty(PKG_OPTIONS:Mgtk)
.include "../../graphics/gtkglext/buildlink3.mk"
.endif
.endif

CONFIGURE_ARGS+=	--enable-renderer=${GNASH_RENDERS:tW:S/ /,/}

###
### Select a media handler
###
.if !empty(PKG_OPTIONS:Mffmpeg)
CONFIGURE_ARGS+=	--enable-media=ffmpeg
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../multimedia/ffmpeg-devel/buildlink3.mk"
# is ffmpeg-devel buildlink broken? we need all that:
.include "../../audio/faac/buildlink3.mk"
.include "../../audio/lame/buildlink3.mk"
.include "../../multimedia/libtheora/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../multimedia/x264-devel/buildlink3.mk"
# --------------------------------------------------
.endif

.if !empty(PKG_OPTIONS:Mgstreamer)
CONFIGURE_ARGS+=	--enable-media=gst --enable-gstreamer
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
# see http://bjacques.org/gst-plugins
DEPENDS+= gst-plugins0.10-base-[0-9]*:../../multimedia/gst-plugins0.10-base
DEPENDS+= gst-plugins0.10-oss-[0-9]*:../../audio/gst-plugins0.10-oss
DEPENDS+= gst-fluendo-mp3-0.10.[0-9]*:../../audio/gst-plugins0.10-fluendo-mp3
DEPENDS+= gst-ffmpeg-0.10.[0-9]*:../../multimedia/gst-plugins0.10-ffmpeg
DEPENDS+= gst-plugins0.10-gnomevfs-[0-9]*:../../sysutils/gst-plugins0.10-gnomevfs
DEPENDS+= gst-plugins0.10-x11-[0-9]*:../../x11/gst-plugins0.10-x11
.endif

###
### MIT-SHM Support.
###
.if !empty(PKG_OPTIONS:Mmitshm)
CONFIGURE_ARGS+=	--enable-mit-shm
.else
CONFIGURE_ARGS+=	--disable-mit-shm
.endif
