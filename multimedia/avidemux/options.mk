# $NetBSD: options.mk,v 1.2 2024/08/25 06:19:03 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.avidemux
PKG_SUPPORTED_OPTIONS=	pulseaudio
PKG_SUGGESTED_OPTIONS=	pulseaudio

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpulseaudio)
.include "../../audio/pulseaudio/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DNO_PULSE_SIMPLE:BOOL=TRUE
.endif
