# $NetBSD: options.mk,v 1.32 2018/12/14 09:09:59 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.musicpd
PKG_SUPPORTED_OPTIONS=	adplug audiofile avahi bzip2 curl faad ffmpeg flac fluidsynth game-music-emu id3 inet6 libao lame jack libmms libmpdclient libsoxr libwildmidi mikmod modplug mpg123 musepack musicpd-soundcloud openal opus pulseaudio shine shout sqlite3 tremor twolame vorbis wavpack zziplib
PKG_SUGGESTED_OPTIONS=	audiofile curl faad flac id3 inet6 libao musepack vorbis

PKG_OPTIONS_OPTIONAL_GROUPS=	vorbis
PKG_OPTIONS_GROUP.vorbis=	tremor vorbis

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Madplug)
.  include "../../audio/adplug/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Maudiofile)
BUILDLINK_API_DEPENDS.libaudiofile+=	libaudiofile>=0.3
.  include "../../audio/libaudiofile/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mavahi)
.  include "../../net/avahi/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mbzip2)
.  include "../../archivers/bzip2/buildlink3.mk"
.endif

# wants a different version of the library than we have in pkgsrc
#.if !empty(PKG_OPTIONS:Mcdparanoia)
#.  include "../../audio/cdparanoia/buildlink3.mk"
#.endif

.if !empty(PKG_OPTIONS:Mcurl)
.  include "../../www/curl/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mfaad)
.  include "../../audio/faad2/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mffmpeg)
.  include "../../multimedia/ffmpeg4/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mflac)
BUILDLINK_ABI_DEPENDS.flac+=	flac>=1.2
.  include "../../audio/flac/buildlink3.mk"
# XXX whole album flac files can appearently be parsed without libcue,
# so I've yet to find out what libcue is good for
#.  include "../../audio/libcue/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mfluidsynth)
.  include "../../audio/fluidsynth/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mgame-music-emu)
.  include "../../audio/game-music-emu/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mid3)
.  include "../../audio/libid3tag/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Minet6)
.endif

.if !empty(PKG_OPTIONS:Mjack)
.  include "../../audio/jack/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mlame)
.  include "../../audio/lame/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mlibao)
.  include "../../audio/libao/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mlibmms)
.  include "../../net/libmms/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mlibmpdclient)
.  include "../../audio/libmpdclient/buildlink3.mk"
.endif

# does not find libresid-builder
#.if !empty(PKG_OPTIONS:Mlibsidplay2)
#.  include "../../audio/libsidplay2/buildlink3.mk"
#.endif

.if !empty(PKG_OPTIONS:Mlibsoxr)
.  include "../../audio/libsoxr/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mlibwildmidi)
.  include "../../audio/libwildmidi/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mmikmod)
.  include "../../audio/libmikmod/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mmodplug)
.  include "../../audio/libmodplug/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mmpg123)
.  include "../../audio/mpg123/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mmusepack)
.  include "../../audio/musepack/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mmusicpd-soundcloud)
BUILDLINK_API_DEPENDS.yajl+=	yajl>=2.1
.  include "../../devel/yajl/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mopenal)
.  include "../../audio/openal-soft/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mopus)
.  include "../../audio/libopus/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
.  include "../../audio/pulseaudio/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mshine)
.  include "../../audio/shine/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mshout)
.  include "../../audio/libshout/buildlink3.mk"
.  include "../../audio/lame/buildlink3.mk"
.endif

# needs libresid-builder or libsidutils, both not packaged yet
#.if !empty(PKG_OPTIONS:Msidplay)
#.  include "../../audio/libsidplay2/buildlink3.mk"
#.endif

.if !empty(PKG_OPTIONS:Msqlite3)
.  include "../../databases/sqlite3/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mtremor)
.  include "../../audio/tremor/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mtwolame)
.  include "../../audio/twolame/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mvorbis)
.  include "../../audio/libvorbis/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mwavpack)
.  include "../../audio/wavpack/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mzziplib)
.  include "../../archivers/zziplib/buildlink3.mk"
.endif
