# $NetBSD: options.mk,v 1.1.2.2 2009/01/14 06:51:13 rtr Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.avidemux
PKG_SUPPORTED_OPTIONS=	pulseaudio
PKG_SUGGESTED_OPTIONS=	pulseaudio

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpulseaudio)
.include "../../audio/pulseaudio/buildlink3.mk"
.else
CMAKE_ARGS+=	-DNO_PULSE_SIMPLE:BOOL=TRUE
.endif
