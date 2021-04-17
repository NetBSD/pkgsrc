# $NetBSD: options.mk,v 1.1 2021/04/17 09:10:38 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.darkice

# Audio codec options
PKG_SUPPORTED_OPTIONS+=		faac lame opus twolame vorbis
# Audio input options
PKG_SUPPORTED_OPTIONS+=		alsa jack pulseaudio
# Misc options
PKG_SUPPORTED_OPTIONS+=		samplerate

PKG_SUGGESTED_OPTIONS+=		faac lame opus twolame vorbis
PKG_SUGGESTED_OPTIONS+=		samplerate
PKG_SUGGESTED_OPTIONS.Linux=	alsa

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
CONFIGURE_ARGS+=	--with-alsa
.include "../../audio/alsa-lib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-alsa
.endif

.if !empty(PKG_OPTIONS:Mfaac)
CONFIGURE_ARGS+=	--with-faac-prefix=${BUILDLINK_PREFIX.faac}
.include "../../audio/faac/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-faac
.endif

.if !empty(PKG_OPTIONS:Mjack)
CONFIGURE_ARGS+=	--with-jack
.include "../../audio/jack/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-jack
.endif

.if !empty(PKG_OPTIONS:Mlame)
CONFIGURE_ARGS+=	--with-lame-prefix=${BUILDLINK_PREFIX.lame}
.include "../../audio/lame/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-lame
.endif

.if !empty(PKG_OPTIONS:Mopus)
CONFIGURE_ARGS+=	--with-opus
.include "../../audio/libopus/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-opus
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
CONFIGURE_ARGS+=	--with-pulseaudio
.include "../../audio/pulseaudio/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-pulseaudio
.endif

.if !empty(PKG_OPTIONS:Msamplerate)
CONFIGURE_ARGS+=	--with-samplerate
.include "../../audio/libsamplerate/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-samplerate
.endif

.if !empty(PKG_OPTIONS:Mtwolame)
CONFIGURE_ARGS+=	--with-twolame
.include "../../audio/twolame/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-twolame
.endif

.if !empty(PKG_OPTIONS:Mvorbis)
CONFIGURE_ARGS+=	--with-vorbis
.include "../../audio/libvorbis/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-vorbis
.endif
