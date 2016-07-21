# $NetBSD: options.mk,v 1.2 2016/07/21 12:49:41 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libopenmpt
PKG_SUPPORTED_OPTIONS=	flac pulseaudio sndfile wavpack
PKG_SUGGESTED_OPTIONS=	pulseaudio sndfile

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mflac)
.include "../../audio/flac/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
.include "../../audio/pulseaudio/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-pulseaudio
.endif

.if !empty(PKG_OPTIONS:Msndfile)
.include "../../audio/libsndfile/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mwavpack)
.include "../../audio/wavpack/buildlink3.mk"
.endif
