# $NetBSD: options.mk,v 1.4 2021/09/17 00:10:21 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.gpac
PKG_SUPPORTED_OPTIONS=		alsa jack pulseaudio x11

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} == "Linux"
PKG_SUGGESTED_OPTIONS=		alsa x11
.else
PKG_SUGGESTED_OPTIONS=		x11
.endif

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		alsa
.if !empty(PKG_OPTIONS:Malsa)
PLIST.alsa=		yes
CONFIGURE_ARGS+=	--enable-alsa
.include "../../audio/alsa-lib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-alsa
.endif

PLIST_VARS+=		jack
.if !empty(PKG_OPTIONS:Mjack)
PLIST.jack=		yes
CONFIGURE_ARGS+=	--enable-jack
.include "../../audio/jack/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-jack
.endif

PLIST_VARS+=		pulseaudio
.if !empty(PKG_OPTIONS:Mpulseaudio)
PLIST.pulseaudio=	yes
CONFIGURE_ARGS+=	--enable-pulseaudio
.include "../../audio/pulseaudio/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-pulseaudio
.endif

PLIST_VARS+=		x11
.if !empty(PKG_OPTIONS:Mx11)
CONFIGURE_ARGS+=	--X11-path=${X11BASE}
PLIST.x11=		yes
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"
.endif
