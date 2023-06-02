# $NetBSD: options.mk,v 1.2 2023/06/02 13:40:19 plunky Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.phonon
PKG_SUPPORTED_OPTIONS=	pulseaudio
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpulseaudio)
.include "../../audio/pulseaudio/buildlink3.mk"
.else
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_PulseAudio:BOOL=TRUE
.endif
