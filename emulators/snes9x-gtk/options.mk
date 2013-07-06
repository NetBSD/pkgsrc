# $NetBSD: options.mk,v 1.1 2013/07/06 16:19:41 rodent Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.snes9x-gtk
PKG_SUPPORTED_OPTIONS=	alsa opengl png pulseaudio xrandr xvideo zlib
PKG_SUGGESTED_OPTIONS+=	png xrandr xvideo zlib

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
.include "../../audio/alsa-lib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-alsa
.endif

.if !empty(PKG_OPTIONS:Mopengl)
.include "../../graphics/MesaLib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-opengl
.endif

.if !empty(PKG_OPTIONS:Mpng)
.include "../../graphics/png/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-screenshot
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
.include "../../audio/pulseaudio/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-pulseaudio
.endif

.if !empty(PKG_OPTIONS:Mxrandr)
.include "../../x11/libXrandr/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-xrandr
.endif

.if !empty(PKG_OPTIONS:Mxvideo)
.include "../../x11/libXv/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-xv
.endif

.if !empty(PKG_OPTIONS:Mzlib)
.include "../../devel/zlib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-zlib
.endif
