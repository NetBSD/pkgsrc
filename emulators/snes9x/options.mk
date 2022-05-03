# $NetBSD: options.mk,v 1.1 2022/05/03 17:09:19 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.snes9x
PKG_SUPPORTED_OPTIONS=		alsa

.include "../../mk/bsd.fast.prefs.mk"
.include "../../mk/oss.buildlink3.mk"

.if ${OPSYS} == "Linux" || ${OSS_TYPE} == "none"
PKG_SUGGESTED_OPTIONS=		alsa
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
CONFIGURE_ARGS+=	--enable-sound-alsa
.  include "../../audio/alsa-lib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--enable-sound

SUBST_CLASSES+=		oss
SUBST_STAGE.oss=	pre-configure
SUBST_MESSAGE.oss=	Correct path to OSS device.
SUBST_FILES.oss+=	unix/unix.cpp
SUBST_SED.oss=		-e "s,/dev/dsp,${DEVOSSAUDIO},g"
.endif
