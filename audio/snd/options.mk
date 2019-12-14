# $NetBSD: options.mk,v 1.9 2019/12/14 18:34:18 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.snd
PKG_SUPPORTED_OPTIONS=
# ruby, forth, alsa, oss, jack, pulseaudio, gmp, ladspa
PKG_OPTIONS_REQUIRED_GROUPS=	frontend
PKG_OPTIONS_GROUP.frontend=	gtk motif

PKG_SUPPORTED_OPTIONS+=		alsa jack portaudio pulseaudio ladspa
PKG_SUGGESTED_OPTIONS.Linux+=	alsa
PKG_SUGGESTED_OPTIONS+=		gtk ladspa

.include "../../mk/oss.buildlink3.mk"

.if ${OSS_TYPE} == "none" && ${OPSYS} != "Linux"
PKG_SUGGESTED_OPTIONS+=		portaudio
.endif

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

.if !empty(PKG_OPTIONS:Mportaudio)
CONFIGURE_ARGS+=	--with-portaudio
.include "../../audio/portaudio/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-portaudio
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
