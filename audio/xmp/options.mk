# $NetBSD: options.mk,v 1.2 2011/04/05 05:22:52 rxg Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.xmp
PKG_SUPPORTED_OPTIONS=	alsa arts esound nas oss pulseaudio

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
PKG_SUGGESTED_OPTIONS=	alsa
.elif ${OPSYS} == "Darwin" || ${OPSYS} == "Interix"
# No native support for these OS's, so use esound for audio output
PKG_SUGGESTED_OPTIONS=	esound
.endif
PKG_SUGGESTED_OPTIONS+=	pulseaudio

.include "../../mk/bsd.options.mk"

# Alsa support
.if !empty(PKG_OPTIONS:Malsa)
.  include "../../audio/alsa-lib/buildlink3.mk"
.else
CONFIGURE_ARGS+=--disable-alsa
.endif

# Arts support
.if !empty(PKG_OPTIONS:Marts)
CONFIGURE_ARGS+=--enable-arts
.  include "../../audio/arts/buildlink3.mk"
.endif

# Esd support
.if !empty(PKG_OPTIONS:Mesound)
CONFIGURE_ARGS+=--enable-esd
.  include "../../audio/esound/buildlink3.mk"
.endif

# Nas support
.if !empty(PKG_OPTIONS:Mnas)
CONFIGURE_ARGS+=--enable-nas
.  include "../../audio/nas/buildlink3.mk"
.endif

# Oss support
.if !empty(PKG_OPTIONS:Moss)
# empty
.else
CONFIGURE_ARGS+=--disable-oss
CONFIGURE_ARGS+=--disable-oss-sequencer
.endif

# Pulseaudio support
.if !empty(PKG_OPTIONS:Mpulseaudio)
CONFIGURE_ARGS+=--enable-pulseaudio
.  include "../../audio/pulseaudio/buildlink3.mk"
.endif
