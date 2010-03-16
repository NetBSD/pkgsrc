# $NetBSD: options.mk,v 1.9 2010/03/16 16:46:22 ahoka Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.cmus
PKG_SUPPORTED_OPTIONS=		flac mad vorbis arts libao mpcdec faad wavpack pulseaudio
PKG_SUPPORTED_OPTIONS+=		wide-curses ffmpeg
PKG_OPTIONS_OPTIONAL_GROUPS=	mod
PKG_OPTIONS_GROUP.mod=		modplug mikmod
PKG_SUGGESTED_OPTIONS=		flac mad libao vorbis modplug
PKG_OPTIONS_LEGACY_OPTS=	ao:libao

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	${PKG_SUPPORTED_OPTIONS}

###
### Backends
###

# AO support
#
.if !empty(PKG_OPTIONS:Mlibao)
.  include "../../audio/libao/buildlink3.mk"
CONFIGURE_ARGS+=	CONFIG_AO=y
PLIST.libao=		yes
.else
CONFIGURE_ARGS+=	CONFIG_AO=n
.endif

# ARTS support
#
.if !empty(PKG_OPTIONS:Marts)
.  include "../../audio/arts/buildlink3.mk"
CONFIGURE_ARGS+=	CONFIG_ARTS=y
PLIST.arts=		yes
.else
CONFIGURE_ARGS+=	CONFIG_ARTS=n
.endif

# ALSA support
#
# UNTESTED
#.if !empty(PKG_OPTIONS:Malsa)
#ONLY_FOR_PLATFORM=  Linux-*-* # Alsa is Linux only
#CONFIGURE_ARGS+=	CONFIG_ALSA=y
#.endif

# PULSE support
#
.if !empty(PKG_OPTIONS:Mpulseaudio)
. include "../../audio/pulseaudio/buildlink3.mk"
CONFIGURE_ARGS+=	CONFIG_PULSE=y
PLIST.pulseaudio=		yes
.else
CONFIGURE_ARGS+=	CONFIG_PULSE=n
.endif

###
### Codecs
###

# MAD support
#
.if !empty(PKG_OPTIONS:Mmad)
.include "../../audio/libmad/buildlink3.mk"
CONFIGURE_ARGS+=	CONFIG_MAD=y
PLIST.mad=		yes
.else
CONFIGURE_ARGS+=	CONFIG_MAD=n
.endif

# VORBIS support
#
.if !empty(PKG_OPTIONS:Mvorbis)
.include "../../audio/libvorbis/buildlink3.mk"
CONFIGURE_ARGS+=	CONFIG_VORBIS=y
PLIST.vorbis=		yes
.else
CONFIGURE_ARGS+=	CONFIG_VORBIS=n
.endif

# FLAC support
#
.if !empty(PKG_OPTIONS:Mflac)
.include "../../audio/flac/buildlink3.mk"
CONFIGURE_ARGS+=	CONFIG_FLAC=y
PLIST.flac=		yes
.else
CONFIGURE_ARGS+=	CONFIG_FLAC=n
.endif

# MPCDEC support
#
.if !empty(PKG_OPTIONS:Mmpcdec)
.include "../../audio/libmpcdec/buildlink3.mk"
CONFIGURE_ARGS+=	CONFIG_MPC=y
PLIST.mpcdec=		yes
.else
CONFIGURE_ARGS+=	CONFIG_MPC=n
.endif

# VAWPACK support
#
.if !empty(PKG_OPTIONS:Mwavpack)
.include "../../audio/wavpack/buildlink3.mk"
CONFIGURE_ARGS+=	CONFIG_WAVPACK=y
PLIST.wavpack=		yes
.else
CONFIGURE_ARGS+=	CONFIG_WAVPACK=n
.endif

# FFMPEG support
#
.if !empty(PKG_OPTIONS:Mffmpeg)
.include "../../multimedia/ffmpeg/buildlink3.mk"
CONFIGURE_ARGS+=	CONFIG_FFMPEG=y
PLIST.ffmpeg=		yes
.else
CONFIGURE_ARGS+=	CONFIG_FFMPEG=n
.endif

# modplay support
#
.if !empty(PKG_OPTIONS:Mmikmod)
.include "../../audio/libmikmod/buildlink3.mk"
.include "../../audio/libaudiofile/buildlink3.mk"
CONFIGURE_ARGS+=	CONFIG_MODPLUG=n
CONFIGURE_ARGS+=	CONFIG_MIKMOD=y
PLIST.mikmod=		yes
.endif
.if !empty(PKG_OPTIONS:Mmodplug)
.include "../../audio/libmodplug/buildlink3.mk"
CONFIGURE_ARGS+=	CONFIG_MODPLUG=y
CONFIGURE_ARGS+=	CONFIG_MIKMOD=n
PLIST.modplug=		yes
.endif

# FAAD support
#
.if !empty(PKG_OPTIONS:Mfaad)
.include "../../audio/faad2/buildlink3.mk"
.include "../../multimedia/libmp4v2/buildlink3.mk"
CONFIGURE_ARGS+=	CONFIG_AAC=y
CONFIGURE_ARGS+=	CONFIG_MP4=y
PLIST.faad=		yes
.else
CONFIGURE_ARGS+=	CONFIG_AAC=n
CONFIGURE_ARGS+=	CONFIG_MP4=n
.endif

###
### Wide curses support; otherwise, default to using narrow curses.
###
# cmus works fine with a 5.0+ NetBSD curses
.if !empty(MACHINE_PLATFORM:MNetBSD-[5-9].*-*)
.    include "../../mk/curses.buildlink3.mk"
.else
.  if !empty(PKG_OPTIONS:Mwide-curses)
.    include "../../devel/ncursesw/buildlink3.mk"
.  else
.    include "../../devel/ncurses/buildlink3.mk"
.  endif
.endif
