# $NetBSD: options.mk,v 1.1 2020/03/23 18:54:51 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.fmsx
PKG_SUPPORTED_OPTIONS=		pulseaudio
PKG_SUGGESTED_OPTIONS.Linux=	pulseaudio

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpulseaudio)
.  include "../../audio/pulseaudio/buildlink3.mk"
.else
BUILDLINK_TRANSFORM+=	rm:-DPULSE_AUDIO
BUILDLINK_TRANSFORM+=	rm:-lpulse-simple
.  include "../../mk/bsd.fast.prefs.mk"
.  include "../../mk/oss.buildlink3.mk"
.  if exists(/usr/include/sys/audioio.h) || \
   ${OPSYS} == "SunOS" || ${OPSYS} == "NetBSD"
DEFS+=			-DSUN_AUDIO
.  elif ${OSS_TYPE} != "none"
DEFS+=			-DOSS_AUDIO
LDFLAGS+=		${LIBOSSAUDIO}
.  else
PKG_FAIL_REASON+=	"No usable audio device"
.  endif
.endif
