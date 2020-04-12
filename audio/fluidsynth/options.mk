# $NetBSD: options.mk,v 1.4 2020/04/12 11:21:10 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.fluidsynth

# Audio backends
PKG_SUPPORTED_OPTIONS=		alsa jack portaudio pulseaudio sdl2
PKG_SUGGESTED_OPTIONS.Linux=	alsa
# Misc
PKG_SUPPORTED_OPTIONS=		dbus ladspa

.include "../../mk/oss.buildlink3.mk"

# On platforms without a native-ish backend, build the SDL2 backend.
.if ${OPSYS} != "Linux" && ${OPSYS} != Darwin && ${OSS_TYPE} == "none"
PKG_SUGGESTED_OPTIONS+=		sdl2
.endif

# A guess at platforms where ladspa is likely to work...
.if ${OPSYS} == "Linux" || !empty(OPSYS:M*BSD) || ${OPSYS} == "DragonFly"
PKG_SUGGESTED_OPTIONS+=		ladspa
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
CMAKE_ARGS+=	-Denable-alsa=ON
.include "../../audio/alsa-lib/buildlink3.mk"
.else
CMAKE_ARGS+=	-Denable-alsa=OFF
.endif

.if !empty(PKG_OPTIONS:Mdbus)
CMAKE_ARGS+=	-Denable-dbus=ON
.include "../../sysutils/dbus/buildlink3.mk"
.else
CMAKE_ARGS+=	-Denable-dbus=OFF
.endif

.if !empty(PKG_OPTIONS:Mjack)
CMAKE_ARGS+=	-Denable-jack=ON
.include "../../audio/jack/buildlink3.mk"
.else
CMAKE_ARGS+=	-Denable-jack=OFF
.endif

.if !empty(PKG_OPTIONS:Mportaudio)
CMAKE_ARGS+=	-Denable-portaudio=ON
.include "../../audio/portaudio/buildlink3.mk"
.else
CMAKE_ARGS+=	-Denable-portaudio=OFF
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
CMAKE_ARGS+=	-Denable-pulseaudio=ON
.include "../../audio/pulseaudio/buildlink3.mk"
.else
CMAKE_ARGS+=	-Denable-pulseaudio=OFF
.endif

.if !empty(PKG_OPTIONS:Msdl2)
CMAKE_ARGS+=	-Denable-sdl2=ON
.include "../../devel/SDL2/buildlink3.mk"
.else
CMAKE_ARGS+=	-Denable-sdl2=OFF
.endif

.if !empty(PKG_OPTIONS:Mladspa)
CMAKE_ARGS+=	-Denable-ladspa=ON
.include "../../audio/ladspa/buildlink3.mk"
.else
CMAKE_ARGS+=	-Denable-ladspa=OFF
.endif
