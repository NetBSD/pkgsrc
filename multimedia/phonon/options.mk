# $NetBSD: options.mk,v 1.1 2013/05/21 12:13:14 markd Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.phonon
PKG_SUPPORTED_OPTIONS=	pulseaudio
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpulseaudio)
.include "../../audio/pulseaudio/buildlink3.mk"
.else
CMAKE_ARGS+=	-DWITH_PulseAudio:BOOL=OFF
.endif
