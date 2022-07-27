# $NetBSD: options.mk,v 1.44 2022/07/27 09:42:45 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.musicpd

# audio outputs
PKG_SUPPORTED_OPTIONS+=	jack openal libao pulseaudio
# codecs
PKG_SUPPORTED_OPTIONS+=	adplug faad ffmpeg fluidsynth libgme libwildmidi
PKG_SUPPORTED_OPTIONS+=	mikmod modplug musepack sidplay wavpack
# codecs (encoding only)
PKG_SUPPORTED_OPTIONS+=	lame shine twolame
# archive formats
PKG_SUPPORTED_OPTIONS+=	bzip2 zziplib
# networking/comms
PKG_SUPPORTED_OPTIONS+=	avahi curl dbus libmms samba shout upnp
# misc
PKG_SUPPORTED_OPTIONS+=	cdparanoia chromaprint musicpd-soundcloud libmpdclient

# no packages yet
# pipewire
# snapcast
# currently broken build:
# sid

PKG_SUGGESTED_OPTIONS=	curl faad ffmpeg libao musepack samplerate shout vorbis
PKG_SUGGESTED_OPTIONS+=	wavpack

PKG_OPTIONS_LEGACY_OPTS+=	game-music-emu:libgme

PKG_OPTIONS_OPTIONAL_GROUPS=	resampler vorbis
PKG_OPTIONS_GROUP.vorbis=	tremor vorbis
PKG_OPTIONS_GROUP.resampler=	samplerate libsoxr

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Madplug)
.  include "../../audio/adplug/buildlink3.mk"
.else
MESON_ARGS+=	-Dadplug=disabled
.endif

.if !empty(PKG_OPTIONS:Mavahi)
.  include "../../net/avahi/buildlink3.mk"
MESON_ARGS+=	-Dzeroconf=avahi
.else
MESON_ARGS+=	-Dzeroconf=auto
.endif

.if !empty(PKG_OPTIONS:Mbzip2)
.  include "../../archivers/bzip2/buildlink3.mk"
.else
MESON_ARGS+=	-Dbzip2=disabled
.endif

.if !empty(PKG_OPTIONS:Mcdparanoia)
.  include "../../misc/libcdio-paranoia/buildlink3.mk"
.else
MESON_ARGS+=	-Dcdio_paranoia=disabled
.endif

.if !empty(PKG_OPTIONS:Mchromaprint)
.  include "../../audio/chromaprint/buildlink3.mk"
.else
MESON_ARGS+=	-Dchromaprint=disabled
.endif

.if !empty(PKG_OPTIONS:Mcurl)
.  include "../../www/curl/buildlink3.mk"
.else
MESON_ARGS+=	-Dcurl=disabled
.endif

.if !empty(PKG_OPTIONS:Mdbus)
.  include "../../sysutils/dbus/buildlink3.mk"
.else
MESON_ARGS+=	-Ddbus=disabled
.endif

.if !empty(PKG_OPTIONS:Mfaad)
.  include "../../audio/faad2/buildlink3.mk"
.else
MESON_ARGS+=	-Dfaad=disabled
.endif

.if !empty(PKG_OPTIONS:Mffmpeg)
.  include "../../multimedia/ffmpeg5/buildlink3.mk"
.else
MESON_ARGS+=	-Dffmpeg=disabled
.endif

.if !empty(PKG_OPTIONS:Mfluidsynth)
.  include "../../audio/fluidsynth/buildlink3.mk"
.else
MESON_ARGS+=	-Dfluidsynth=disabled
.endif

.if !empty(PKG_OPTIONS:Mlibgme)
.  include "../../audio/game-music-emu/buildlink3.mk"
.else
MESON_ARGS+=	-Dgme=disabled
.endif

.if !empty(PKG_OPTIONS:Mjack)
.  include "../../audio/jack/buildlink3.mk"
.else
MESON_ARGS+=	-Djack=disabled
.endif

.if !empty(PKG_OPTIONS:Mlame)
.  include "../../audio/lame/buildlink3.mk"
.else
MESON_ARGS+=	-Dlame=disabled
.endif

.if !empty(PKG_OPTIONS:Mlibao)
.  include "../../audio/libao/buildlink3.mk"
.else
MESON_ARGS+=	-Dao=disabled
.endif

.if !empty(PKG_OPTIONS:Mlibmms)
.  include "../../net/libmms/buildlink3.mk"
.else
MESON_ARGS+=	-Dmms=disabled
.endif

.if !empty(PKG_OPTIONS:Mlibmpdclient)
BUILDLINK_API_DEPENDS.libmpdclient+=	libmpdclient>=2.11
.  include "../../audio/libmpdclient/buildlink3.mk"
.else
MESON_ARGS+=	-Dlibmpdclient=disabled
.endif

.if !empty(PKG_OPTIONS:Mlibsoxr)
.  include "../../audio/libsoxr/buildlink3.mk"
.else
MESON_ARGS+=	-Dsoxr=disabled
.endif

.if !empty(PKG_OPTIONS:Mlibwildmidi)
.  include "../../audio/libwildmidi/buildlink3.mk"
.else
MESON_ARGS+=	-Dwildmidi=disabled
.endif

.if !empty(PKG_OPTIONS:Mmikmod)
.  include "../../audio/libmikmod/buildlink3.mk"
.else
MESON_ARGS+=	-Dmikmod=disabled
.endif

.if !empty(PKG_OPTIONS:Mmodplug)
.  include "../../audio/libmodplug/buildlink3.mk"
.else
MESON_ARGS+=	-Dmodplug=disabled
.endif

.if !empty(PKG_OPTIONS:Mmusepack)
.  include "../../audio/musepack/buildlink3.mk"
.else
MESON_ARGS+=	-Dmpcdec=disabled
.endif

.if !empty(PKG_OPTIONS:Mmusicpd-soundcloud)
BUILDLINK_API_DEPENDS.yajl+=	yajl>=2.1
.  include "../../devel/yajl/buildlink3.mk"
.else
MESON_ARGS+=	-Dyajl=disabled
.endif

.if !empty(PKG_OPTIONS:Mopenal)
.  include "../../audio/openal-soft/buildlink3.mk"
.else
MESON_ARGS+=	-Dopenal=disabled
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
.  include "../../audio/pulseaudio/buildlink3.mk"
.else
MESON_ARGS+=	-Dpulse=disabled
.endif

.if !empty(PKG_OPTIONS:Msamba)
.  include "../../net/samba4/buildlink3.mk"
.else
MESON_ARGS+=	-Dsmbclient=disabled
.endif

.if !empty(PKG_OPTIONS:Msamplerate)
.  include "../../audio/libsamplerate/buildlink3.mk"
.else
MESON_ARGS+=	-Dsamplerate=disabled
.endif

.if !empty(PKG_OPTIONS:Mshine)
.  include "../../audio/shine/buildlink3.mk"
.else
MESON_ARGS+=	-Dshine=disabled
.endif

.if !empty(PKG_OPTIONS:Msidplay)
.  include "../../audio/libsidplay2/buildlink3.mk"
.else
MESON_ARGS+=	-Dsidplay=disabled
.endif

.if !empty(PKG_OPTIONS:Mshout)
BUILDLINK_API_DEPENDS.libshout+=	libshout>=2.4.0
.  include "../../audio/libshout/buildlink3.mk"
.  include "../../audio/lame/buildlink3.mk"
.else
MESON_ARGS+=	-Dshout=disabled
.endif

.if !empty(PKG_OPTIONS:Mtremor)
.  include "../../audio/tremor/buildlink3.mk"
.else
MESON_ARGS+=	-Dtremor=disabled
.endif

.if !empty(PKG_OPTIONS:Mtwolame)
.  include "../../audio/twolame/buildlink3.mk"
.else
MESON_ARGS+=	-Dtwolame=disabled
.endif

.if !empty(PKG_OPTIONS:Mvorbis)
.  include "../../audio/libvorbis/buildlink3.mk"
.else
MESON_ARGS+=	-Dvorbis=disabled
MESON_ARGS+=	-Dvorbisenc=disabled
.endif

.if !empty(PKG_OPTIONS:Mupnp)
.  include "../../net/libnpupnp/buildlink3.mk"
.else
MESON_ARGS+=	-Dupnp=disabled
.endif

.if !empty(PKG_OPTIONS:Mwavpack)
.  include "../../audio/wavpack/buildlink3.mk"
.else
MESON_ARGS+=	-Dwavpack=disabled
.endif

.if !empty(PKG_OPTIONS:Mzziplib)
.  include "../../archivers/zziplib/buildlink3.mk"
.else
MESON_ARGS+=	-Dzzip=disabled
.endif
