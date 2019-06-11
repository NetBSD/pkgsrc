# $NetBSD: options.mk,v 1.7 2019/06/11 11:54:56 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.moc

PKG_SUPPORTED_OPTIONS+=		curl faad flac mad sndfile vorbis
PKG_SUPPORTED_OPTIONS+=		alsa ffmpeg jack modplug samplerate
PKG_SUPPORTED_OPTIONS+=		sidplay speex wavpack wide-curses

PKG_SUGGESTED_OPTIONS+=		curl faad flac mad sndfile vorbis wide-curses
PKG_SUGGESTED_OPTIONS.Linux+=	alsa

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	faad ffmpeg flac mad modplug sidplay sndfile
PLIST_VARS+=	speex vorbis wavpack

.if !empty(PKG_OPTIONS:Malsa)
.  include "../../audio/alsa-lib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-alsa
.endif

.if !empty(PKG_OPTIONS:Mcurl)
.  include "../../www/curl/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-curl
.endif

.if !empty(PKG_OPTIONS:Mfaad)
PLIST.faad=		yes
.  include "../../audio/faad2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-aac
.endif

.if !empty(PKG_OPTIONS:Mffmpeg)
PLIST.ffmpeg=		yes
.  include "../../multimedia/ffmpeg3/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-ffmpeg
.endif

.if !empty(PKG_OPTIONS:Mflac)
PLIST.flac=		yes
.  include "../../audio/flac/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-flac
.endif

.if !empty(PKG_OPTIONS:Mjack)
###
### Resampling support is usually required with jack.
###
.  include "../../audio/jack/buildlink3.mk"
.  include "../../audio/libsamplerate/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-jack
.endif

.if !empty(PKG_OPTIONS:Mmad)
PLIST.mad=		yes
.  include "../../audio/libmad/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-mp3
.endif

.if !empty(PKG_OPTIONS:Mmodplug)
PLIST.modplug=		yes
.  include "../../audio/libmodplug/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-modplug
.endif

.if !empty(PKG_OPTIONS:Msamplerate)
.  include "../../audio/libsamplerate/buildlink3.mk"
.else
.  if empty(PKG_OPTIONS:Mjack)
CONFIGURE_ARGS+=	--without-samplerate
.  endif
.endif

.if !empty(PKG_OPTIONS:Msidplay)
PLIST.sidplay=		yes
.  include "../../audio/libsidplay2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-sidplay2
.endif

.if !empty(PKG_OPTIONS:Msndfile)
PLIST.sndfile=		yes
.  include "../../audio/libsndfile/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-sndfile
.endif

.if !empty(PKG_OPTIONS:Mspeex)
PLIST.speex=		yes
.  include "../../audio/speex/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-speex
.endif

.if !empty(PKG_OPTIONS:Mvorbis)
PLIST.vorbis=		yes
.  include "../../audio/libvorbis/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-vorbis
.endif

.if !empty(PKG_OPTIONS:Mwavpack)
PLIST.wavpack=		yes
.  include "../../audio/wavpack/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-wavpack
.endif

.if !empty(PKG_OPTIONS:Mwide-curses)
# handled by curses.buildlink3.mk
# XXX i'm not sure why this is needed
FAKE_NCURSES=		yes
.endif
