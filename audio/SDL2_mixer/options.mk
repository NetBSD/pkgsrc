# $NetBSD: options.mk,v 1.2 2018/06/24 10:28:45 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.SDL2_mixer
PKG_SUPPORTED_OPTIONS=	flac fluidsynth modplug mpg123 vorbis
PKG_SUGGESTED_OPTIONS+=	flac modplug mpg123 vorbis

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mflac)
.include "../../audio/flac/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-music-flac=yes
.else
CONFIGURE_ARGS+=	--enable-music-flac=no
.endif

.if !empty(PKG_OPTIONS:Mfluidsynth)
.include "../../audio/fluidsynth/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-music-midi-fluidsynth=yes
.else
CONFIGURE_ARGS+=	--enable-music-midi-fluidsynth=no
.endif

.if !empty(PKG_OPTIONS:Mmodplug)
.include "../../audio/libmodplug/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-music-mod-modplug=yes
.else
CONFIGURE_ARGS+=	--enable-music-mod-modplug=no
.endif

.if !empty(PKG_OPTIONS:Mmpg123)
.include "../../audio/mpg123/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-music-mp3-mpg123=yes
.else
CONFIGURE_ARGS+=	--enable-music-mp3-mpg123=no
.endif

.if !empty(PKG_OPTIONS:Mvorbis)
.include "../../audio/libvorbis/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-music-ogg=yes
.else
CONFIGURE_ARGS+=	--enable-music-ogg=no
.endif
