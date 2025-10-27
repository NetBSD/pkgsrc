# $NetBSD: options.mk,v 1.4 2025/10/27 22:57:36 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.flycast

PKG_SUPPORTED_OPTIONS+=		alsa pulseaudio
PKG_SUGGESTED_OPTIONS.Linux+=	alsa

.include "../../mk/bsd.fast.prefs.mk"

.if ${MACHINE_ARCH:M*arm*}
PKG_SUPPORTED_OPTIONS+=		rpi
.endif
.if ${MACHINE_PLATFORM:MNetBSD-*-earmv6hf}
PKG_SUGGESTED_OPTIONS+=		rpi
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
CMAKE_CONFIGURE_ARGS+=		-DUSE_ALSA=ON
.  include "../../audio/alsa-lib/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=		-DUSE_ALSA=OFF
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
CMAKE_CONFIGURE_ARGS+=		-DUSE_PULSEAUDIO=ON
.  include "../../audio/pulseaudio/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=		-DUSE_PULSEAUDIO=OFF
.endif

.if !empty(PKG_OPTIONS:Mrpi)
CMAKE_CONFIGURE_ARGS+=	-DUSE_VIDEOCORE=ON
CMAKE_CONFIGURE_ARGS+=	-DUSE_GLES2=ON
CMAKE_CONFIGURE_ARGS+=	-DUSE_OPENGL=OFF
.  include "../../misc/raspberrypi-userland/buildlink3.mk"
.else
.  if ${OPSYS} != "Darwin"
.    include "../../graphics/MesaLib/buildlink3.mk"
.  endif
.endif
