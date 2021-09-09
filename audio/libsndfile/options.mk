# $NetBSD: options.mk,v 1.11 2021/09/09 12:14:42 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.libsndfile

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
PKG_SUPPORTED_OPTIONS=		alsa octave
PKG_SUGGESTED_OPTIONS=		alsa
.else
PKG_SUPPORTED_OPTIONS=		octave
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
CONFIGURE_ARGS+=	--enable-alsa
.include "../../audio/alsa-lib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-alsa
.endif

.if !empty(PKG_OPTIONS:Moctave)
USE_LANGUAGES=		c c++ fortran
USE_TOOLS+=		gmake
CONFIGURE_ARGS+=	--enable-octave
.include "../../math/octave/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-octave
.endif
