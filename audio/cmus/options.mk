# $NetBSD: options.mk,v 1.2 2007/12/16 21:45:30 rillig Exp $

PKG_OPTIONS_VAR=				PKG_OPTIONS.cmus
PKG_SUPPORTED_OPTIONS=			flac mad vorbis arts ao mpcdec #faad alsa
PKG_OPTIONS_OPTIONAL_GROUPS=	mod
PKG_OPTIONS_GROUP.mod=			modplug mikmod
PKG_SUGGESTED_OPTIONS=			flac mad ao vorbis modplug

.include "../../mk/bsd.prefs.mk"

.include "../../mk/bsd.options.mk"

# Package-specific option-handling

# Backends:
#

# AO support
#
.if !empty(PKG_OPTIONS:Mao)
.  include "../../audio/libao/buildlink3.mk"
CONFIGURE_ARGS+=	CONFIG_AO=y
.else
CONFIGURE_ARGS+=	CONFIG_AO=n
.endif

# ARTS support
#
.if !empty(PKG_OPTIONS:Marts)
.  include "../../audio/arts/buildlink3.mk"
CONFIGURE_ARGS+=	CONFIG_ARTS=y
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

# Codecs:
#

# MAD support
#
.if !empty(PKG_OPTIONS:Mmad)
.include "../../audio/libmad/buildlink3.mk"
CONFIGURE_ARGS+=	CONFIG_MAD=y
.else
CONFIGURE_ARGS+=	CONFIG_MAD=n
.endif

# VORBIS support
#
.if !empty(PKG_OPTIONS:Mvorbis)
.include "../../audio/libvorbis/buildlink3.mk"
CONFIGURE_ARGS+=	CONFIG_VORBIS=y
.else
CONFIGURE_ARGS+=	CONFIG_VORBIS=n
.endif

# FLAC support
#
.if !empty(PKG_OPTIONS:Mflac)
.include "../../audio/flac/buildlink3.mk"
CONFIGURE_ARGS+=	CONFIG_FLAC=y
.else
CONFIGURE_ARGS+=	CONFIG_FLAC=n
.endif

# MPCDEC support
#
.if !empty(PKG_OPTIONS:Mmpcdec)
.include "../../audio/libmpcdec/buildlink3.mk"
CONFIGURE_ARGS+=	CONFIG_MPC=y
.else
CONFIGURE_ARGS+=	CONFIG_MPC=n
.endif

###
### modplay support
###
.if !empty(PKG_OPTIONS:Mmikmod)
.include "../../audio/libmikmod/buildlink3.mk"
CONFIGURE_ARGS+=	CONFIG_MODPLUG=n
CONFIGURE_ARGS+=	CONFIG_MIKMOD=y
.endif
.if !empty(PKG_OPTIONS:Mmodplug)
.include "../../audio/libmodplug/buildlink3.mk"
CONFIGURE_ARGS+=	CONFIG_MODPLUG=y
CONFIGURE_ARGS+=	CONFIG_MIKMOD=n
.endif


# FAAD support
#
# XXX: faad2 in pkgsrc is heavily outdated as of 2007Q3, cmus needs newer.
#
#.if !empty(PKG_OPTIONS:Mfaad)
#.include "../../audio/faad2/buildlink3.mk"
#CONFIGURE_ARGS+=	CONFIG_AAC=y
#CONFIGURE_ARGS+=	CONFIG_MP4=y
#.else
#CONFIGURE_ARGS+=	CONFIG_AAC=n
#CONFIGURE_ARGS+=	CONFIG_MP4=n
#.endif
