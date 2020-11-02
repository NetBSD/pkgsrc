# $NetBSD: options.mk,v 1.10 2020/11/02 10:07:02 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.snd
PKG_SUPPORTED_OPTIONS=

PKG_OPTIONS_REQUIRED_GROUPS=	frontend
PKG_OPTIONS_GROUP.frontend=	gtk motif

PKG_SUPPORTED_OPTIONS+=		ladspa

# Audio backends can seemingly only coeexist on Linux
PKG_SUPPORTED_OPTIONS.Linux+=	alsa jack pulseaudio
PKG_SUGGESTED_OPTIONS.Linux+=	alsa jack

PKG_SUGGESTED_OPTIONS+=		gtk ladspa

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
CONFIGURE_ARGS+=	--with-alsa
.include "../../audio/alsa-lib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-alsa
.endif

.if !empty(PKG_OPTIONS:Mjack)
CONFIGURE_ARGS+=	--with-jack
.include "../../audio/jack/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-jack
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
CONFIGURE_ARGS+=	--with-pulseaudio
.include "../../audio/pulseaudio/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-pulseaudio
.endif

.if !empty(PKG_OPTIONS:Mladspa)
CONFIGURE_ARGS+=	--with-ladspa
.include "../../audio/ladspa/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-ladspa
.endif

.if !empty(PKG_OPTIONS:Mgtk)
CONFIGURE_ARGS+=	--with-gtk
.include "../../x11/gtk3/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-gtk
.endif

.if !empty(PKG_OPTIONS:Mmotif)
CONFIGURE_ARGS+=	--with-motif
.include "../../mk/motif.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-motif
.endif
