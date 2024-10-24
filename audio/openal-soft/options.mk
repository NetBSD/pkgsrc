# $NetBSD: options.mk,v 1.3 2024/08/25 06:18:25 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.openal-soft
PKG_SUPPORTED_OPTIONS=		jack pulseaudio
PKG_SUGGESTED_OPTIONS.Linux+=	alsa

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
# The ALSA backend is known not to work on this platform:
# https://mail-index.netbsd.org/pkgsrc-users/2023/07/17/msg037726.html
.else
PKG_SUPPORTED_OPTIONS+=	alsa
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
CMAKE_CONFIGURE_ARGS+=	-DALSOFT_BACKEND_ALSA=ON
.  include "../../audio/alsa-lib/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DALSOFT_BACKEND_ALSA=OFF
.endif

.if !empty(PKG_OPTIONS:Mjack)
CMAKE_CONFIGURE_ARGS+=	-DALSOFT_BACKEND_JACK=ON
.  include "../../audio/jack/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DALSOFT_BACKEND_JACK=OFF
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
CMAKE_CONFIGURE_ARGS+=	-DALSOFT_BACKEND_PULSEAUDIO=ON
.  include "../../audio/pulseaudio/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DALSOFT_BACKEND_PULSEAUDIO=OFF
.endif
