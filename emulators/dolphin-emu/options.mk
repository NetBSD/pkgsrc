# $NetBSD: options.mk,v 1.3 2019/06/13 19:44:35 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.dolphin-emu
PKG_SUPPORTED_OPTIONS=		alsa libao llvm openal portaudio pulseaudio
PKG_SUGGESTED_OPTIONS+=		alsa libao

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
CMAKE_ARGS+=	-DENABLE_ALSA=ON
.include "../../audio/alsa-lib/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mlibao)
CMAKE_ARGS+=	-DENABLE_AO=ON
.include "../../audio/libao/buildlink3.mk"
.endif

#
# LLVM - Used for disassembly
#
.if !empty(PKG_OPTIONS:Mllvm)
CMAKE_ARGS+=	-DENABLE_LLVM=ON
.include "../../lang/libLLVM/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mopenal)
CMAKE_ARGS+=	-DENABLE_OPENAL=ON
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../audio/soundtouch/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mportaudio)
CMAKE_ARGS+=	-DENABLE_PORTAUDIO=ON
.include "../../audio/portaudio-devel/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
CMAKE_ARGS+=	-DENABLE_PULSEAUDIO=ON
.include "../../audio/pulseaudio/buildlink3.mk"
.endif
