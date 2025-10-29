# $NetBSD: options.mk,v 1.1 2025/10/29 21:38:02 markd Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.phonon
PKG_SUPPORTED_OPTIONS=	pulseaudio
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpulseaudio)
.include "../../audio/pulseaudio/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_PulseAudio:BOOL=TRUE
.endif
