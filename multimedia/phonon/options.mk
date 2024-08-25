# $NetBSD: options.mk,v 1.2 2024/08/25 06:19:05 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.phonon
PKG_SUPPORTED_OPTIONS=	pulseaudio
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpulseaudio)
.include "../../audio/pulseaudio/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DWITH_PulseAudio:BOOL=OFF
.endif
