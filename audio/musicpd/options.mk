# $NetBSD: options.mk,v 1.29 2016/07/16 00:16:41 markd Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.musicpd
PKG_SUPPORTED_OPTIONS=	adplug audiofile avahi bzip2 curl faad ffmpeg flac fluidsynth id3 inet6 libao lame jack libmms libmpdclient libwildmidi mikmod modplug mpg123 musepack musicpd-soundcloud openal opus pulseaudio shout sqlite3 tremor twolame vorbis wavpack zziplib
PKG_SUGGESTED_OPTIONS=	audiofile curl faad flac id3 inet6 libao musepack vorbis

# TODO:
# shine
# libsoxr

PKG_OPTIONS_OPTIONAL_GROUPS=	vorbis
PKG_OPTIONS_GROUP.vorbis=	tremor vorbis

PKG_OPTIONS_LEGACY_OPTS=	ogg:vorbis

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Madplug)
.  include "../../audio/adplug/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-adplug
.else
CONFIGURE_ARGS+=	--disable-adplug
.endif

.if !empty(PKG_OPTIONS:Maudiofile)
BUILDLINK_API_DEPENDS.libaudiofile+=	libaudiofile>=0.3
.  include "../../audio/libaudiofile/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-audiofile
.else
CONFIGURE_ARGS+=	--disable-audiofile
.endif

.if !empty(PKG_OPTIONS:Mavahi)
.  include "../../net/avahi/buildlink3.mk"
CONFIGURE_ARGS+=	--with-zeroconf=avahi
.endif

.if !empty(PKG_OPTIONS:Mbzip2)
.  include "../../archivers/bzip2/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-bzip2
.else
CONFIGURE_ARGS+=	--disable-bzip2
.endif

# wants a different version of the library than we have in pkgsrc
#.if !empty(PKG_OPTIONS:Mcdparanoia)
#.  include "../../audio/cdparanoia/buildlink3.mk"
#CONFIGURE_ARGS+=	--enable-cdio-paranoia
#.else
#CONFIGURE_ARGS+=	--enable-cdio-paranoia
#.endif

.if !empty(PKG_OPTIONS:Mcurl)
.  include "../../www/curl/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-curl
.else
CONFIGURE_ARGS+=	--disable-curl
.endif

.if !empty(PKG_OPTIONS:Mfaad)
.  include "../../audio/faad2/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-aac
.else
CONFIGURE_ARGS+=	--disable-aac
.endif

.if !empty(PKG_OPTIONS:Mffmpeg)
.  include "../../multimedia/ffmpeg3/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-ffmpeg
.else
CONFIGURE_ARGS+=	--disable-ffmpeg
.endif

.if !empty(PKG_OPTIONS:Mflac)
BUILDLINK_ABI_DEPENDS.flac+=	flac>=1.2
.  include "../../audio/flac/buildlink3.mk"
# XXX whole album flac files can appearently be parsed without libcue,
# so I've yet to find out what libcue is good for
#.  include "../../audio/libcue/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-flac
.else
CONFIGURE_ARGS+=	--disable-flac
.endif

.if !empty(PKG_OPTIONS:Mfluidsynth)
.  include "../../audio/fluidsynth/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-fluidsynth
.else
CONFIGURE_ARGS+=	--disable-fluidsynth
.endif

# needs to be imported from wip first
#.if !empty(PKG_OPTIONS:Mgme)
#.  include "../../wip/libgme/buildlink3.mk"
#CONFIGURE_ARGS+=	--enable-gme
#.else
#CONFIGURE_ARGS+=	--disable-gme
#.endif

.if !empty(PKG_OPTIONS:Mid3)
.  include "../../audio/libid3tag/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-id3
.else
CONFIGURE_ARGS+=	--disable-id3
.endif

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if !empty(PKG_OPTIONS:Mjack)
.  include "../../audio/jack/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-jack
.else
CONFIGURE_ARGS+=	--disable-jack
.endif

.if !empty(PKG_OPTIONS:Mlame)
.  include "../../audio/lame/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-lame-encoder
.else
CONFIGURE_ARGS+=	--disable-lame-encoder
.endif

.if !empty(PKG_OPTIONS:Mlibao)
.  include "../../audio/libao/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-ao
.else
CONFIGURE_ARGS+=	--disable-ao
.endif

.if !empty(PKG_OPTIONS:Mlibmms)
.  include "../../net/libmms/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-mms
.else
CONFIGURE_ARGS+=	--disable-mms
.endif

.if !empty(PKG_OPTIONS:Mlibmpdclient)
.  include "../../audio/libmpdclient/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-libmpdclient
.else
CONFIGURE_ARGS+=	--disable-libmpdclient
.endif

# does not find libresid-builder
#.if !empty(PKG_OPTIONS:Mlibsidplay2)
#.  include "../../audio/libsidplay2/buildlink3.mk"
#CONFIGURE_ARGS+=	--enable-sidplay
#.else
#CONFIGURE_ARGS+=	--disable-sidplay
#.endif

.if !empty(PKG_OPTIONS:Mlibwildmidi)
.  include "../../audio/libwildmidi/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-wildmidi
.else
CONFIGURE_ARGS+=	--disable-wildmidi
.endif

.if !empty(PKG_OPTIONS:Mmikmod)
.  include "../../audio/libmikmod/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-mikmod
.else
CONFIGURE_ARGS+=	--disable-mikmod
.endif

.if !empty(PKG_OPTIONS:Mmodplug)
.  include "../../audio/libmodplug/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-modplug
.else
CONFIGURE_ARGS+=	--disable-modplug
.endif

.if !empty(PKG_OPTIONS:Mmpg123)
.  include "../../audio/mpg123/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-mpg123
.else
CONFIGURE_ARGS+=	--disable-mpg123
.endif

.if !empty(PKG_OPTIONS:Mmusepack)
.  include "../../audio/musepack/buildlink3.mk"
CONFIGURE_ENV+=		mpcdec_prefix=${BUILDLINK_PREFIX.musepack}
CONFIGURE_ARGS+=	--enable-mpc
.else
CONFIGURE_ARGS+=	--disable-mpc
.endif

.if !empty(PKG_OPTIONS:Mmusicpd-soundcloud)
BUILDLINK_API_DEPENDS.yajl+=	yajl>=2.1
.  include "../../devel/yajl/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-soundcloud
.else
CONFIGURE_ARGS+=	--disable-soundcloud
.endif

.if !empty(PKG_OPTIONS:Mopenal)
.  include "../../audio/openal-soft/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-openal
.else
CONFIGURE_ARGS+=	--disable-openal
.endif

.if !empty(PKG_OPTIONS:Mopus)
.  include "../../audio/libopus/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-opus
.else
CONFIGURE_ARGS+=	--disable-opus
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
.  include "../../audio/pulseaudio/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-pulse
.else
CONFIGURE_ARGS+=	--disable-pulse
.endif

.if !empty(PKG_OPTIONS:Mshout)
.  include "../../audio/libshout/buildlink3.mk"
.  include "../../audio/lame/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-shout
.else
CONFIGURE_ARGS+=	--disable-shout
.endif

# needs libresid-builder or libsidutils, both not packaged yet
#.if !empty(PKG_OPTIONS:Msidplay)
#.  include "../../audio/libsidplay2/buildlink3.mk"
#CONFIGURE_ARGS+=	--enable-sidplay
#.else
#CONFIGURE_ARGS+=	--disable-sidplay
#.endif

.if !empty(PKG_OPTIONS:Msqlite3)
.  include "../../databases/sqlite3/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-sqlite
.else
CONFIGURE_ARGS+=	--disable-sqlite
.endif

.if !empty(PKG_OPTIONS:Mtremor)
.  include "../../audio/tremor/buildlink3.mk"
CONFIGURE_ARGS+=	--with-tremor=${BUILDLINK_PREFIX.tremor}
.else
CONFIGURE_ARGS+=	--without-tremor
.endif

.if !empty(PKG_OPTIONS:Mtwolame)
.  include "../../audio/twolame/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-twolame-encoder
.else
CONFIGURE_ARGS+=	--disable-twolame-encoder
.endif

.if !empty(PKG_OPTIONS:Mvorbis)
.  include "../../audio/libvorbis/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-vorbis
.else
CONFIGURE_ARGS+=	--disable-vorbis
.endif

.if !empty(PKG_OPTIONS:Mwavpack)
.  include "../../audio/wavpack/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-wavpack
.else
CONFIGURE_ARGS+=	--disable-wavpack
.endif

.if !empty(PKG_OPTIONS:Mzziplib)
.  include "../../archivers/zziplib/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-zzip
.else
CONFIGURE_ARGS+=	--disable-zzip
.endif
