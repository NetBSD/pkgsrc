# $NetBSD: options.mk,v 1.7 2025/12/14 12:00:41 vins Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.sox
PKG_SUPPORTED_OPTIONS=	lame oss sndio
# lame has LICENSE= issues and thus should not be SUGGESTED.
PKG_SUGGESTED_OPTIONS=
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlame)
# This is an option due to LICENSE= issues.
.include "../../audio/lame/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Moss)
LDFLAGS+=		-lossaudio
.include "../../mk/oss.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-oss
.endif

.if !empty(PKG_OPTIONS:Msndio)
.include "../../audio/sndio/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-sndio
.endif
