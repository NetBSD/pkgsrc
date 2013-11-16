# $NetBSD: options.mk,v 1.3 2013/11/16 07:41:02 shattered Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.xmp
# XXX configure.ac is broken, you cannot disable oss and alsa at the moment.
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
.  include "../../mk/oss.buildlink3.mk"
LIBS+=		${LIBOSSAUDIO}
CPPFLAGS+=	-DDEVOSSAUDIO="\"${DEVOSSAUDIO}\""
CPPFLAGS+=	-DDEVOSSSOUND="\"${DEVOSSSOUND}\""
.else
CONFIGURE_ARGS+=--disable-oss
.endif

# Pulseaudio support
.if !empty(PKG_OPTIONS:Mpulseaudio)
CONFIGURE_ARGS+=--enable-pulseaudio
.  include "../../audio/pulseaudio/buildlink3.mk"
.endif
