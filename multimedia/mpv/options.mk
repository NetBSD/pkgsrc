# $NetBSD: options.mk,v 1.34 2023/08/15 19:17:10 leot Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mpv


PKG_OPTIONS_OPTIONAL_GROUPS=	gl
PKG_OPTIONS_GROUP.gl=		opengl rpi

# audio outputs
PKG_SUPPORTED_OPTIONS+=		alsa jack openal pulseaudio
# video outputs
PKG_SUPPORTED_OPTIONS+=		caca libdrm sixel x11
# audio/video outputs
PKG_SUPPORTED_OPTIONS+=		sdl2
# misc
PKG_SUPPORTED_OPTIONS+=		bluray lua

PKG_SUGGESTED_OPTIONS=		bluray lua sdl2 sixel
PKG_SUGGESTED_OPTIONS.Linux+=	alsa pulseaudio

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} != "Darwin"
PKG_SUGGESTED_OPTIONS+=		opengl x11
.endif

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "Linux"
PKG_SUGGESTED_OPTIONS+=		libdrm
.endif

.include "../../multimedia/libva/available.mk"

.if ${VAAPI_AVAILABLE} == "yes"
PKG_SUPPORTED_OPTIONS+=		vaapi
PKG_SUGGESTED_OPTIONS+=		vaapi
.endif

.include "../../multimedia/libvdpau/available.mk"

.if ${VDPAU_AVAILABLE} == "yes"
PKG_SUPPORTED_OPTIONS+=		vdpau
PKG_SUGGESTED_OPTIONS+=		vdpau
.endif

.include "../../mk/bsd.options.mk"

###
### alsa support (audio output)
###
.if !empty(PKG_OPTIONS:Malsa)
MESON_ARGS+=	-Dalsa=enabled
.include "../../audio/alsa-lib/buildlink3.mk"
.else
MESON_ARGS+=	-Dalsa=disabled
.endif

###
### libbluray support
###
.if !empty(PKG_OPTIONS:Mbluray)
MESON_ARGS+=	-Dlibbluray=enabled
.include "../../multimedia/libbluray/buildlink3.mk"
.else
MESON_ARGS+=	-Dlibbluray=disabled
.endif

###
### caca support (video output)
###
.if !empty(PKG_OPTIONS:Mcaca)
MESON_ARGS+=	-Dcaca=enabled
.include "../../graphics/libcaca/buildlink3.mk"
.else
MESON_ARGS+=	-Dcaca=disabled
.endif

###
### lua support
###
.if !empty(PKG_OPTIONS:Mlua)
MESON_ARGS+=	-Dlua=enabled
LUA_VERSIONS_ACCEPTED=	52 51
.include "../../lang/lua/buildlink3.mk"
.else
MESON_ARGS+=	-Dlua=disabled
.endif

###
### JACK support (audio output)
###
.if !empty(PKG_OPTIONS:Mjack)
MESON_ARGS+=	-Djack=enabled
.include "../../audio/jack/buildlink3.mk"
.else
MESON_ARGS+=	-Djack=disabled
.endif


###
### OpenAL support (audio output)
###
.if !empty(PKG_OPTIONS:Mopenal)
MESON_ARGS+=	-Dopenal=enabled
.include "../../audio/openal-soft/buildlink3.mk"
.else
MESON_ARGS+=	-Dopenal=disabled
.endif

###
### PulseAudio support (audio output)
###
.if !empty(PKG_OPTIONS:Mpulseaudio)
MESON_ARGS+=	-Dpulse=enabled
.include "../../audio/pulseaudio/buildlink3.mk"
.else
MESON_ARGS+=	-Dpulse=disabled
.endif

###
### SDL2 support (audio and video output)
###
.if !empty(PKG_OPTIONS:Msdl2)
MESON_ARGS+=	-Dsdl2-audio=enabled
MESON_ARGS+=	-Dsdl2=enabled
.include "../../devel/SDL2/buildlink3.mk"
.else
MESON_ARGS+=	-Dsdl2-audio=disabled
MESON_ARGS+=	-Dsdl2=disabled
.endif

###
### VAAPI support (video output)
###
.if !empty(PKG_OPTIONS:Mvaapi)
MESON_ARGS+=	-Dvaapi=enabled
.include "../../multimedia/libva/buildlink3.mk"
.else
MESON_ARGS+=	-Dvaapi=disabled
.endif

###
### VDPAU support (video output)
###
.if !empty(PKG_OPTIONS:Mvdpau)
MESON_ARGS+=	-Dvdpau=enabled
.include "../../multimedia/libvdpau/buildlink3.mk"
.else
MESON_ARGS+=	-Dvdpau=disabled
.endif

###
### libdrm support (video output)
###
.if !empty(PKG_OPTIONS:Mlibdrm)
MESON_ARGS+=	-Ddrm=enabled
.include "../../x11/libdrm/buildlink3.mk"
.else
MESON_ARGS+=	-Ddrm=disabled
.endif

###
### OpenGL support (video output)
###
.if !empty(PKG_OPTIONS:Mopengl)
.include "../../graphics/MesaLib/features.mk"
.  if ${MESALIB_SUPPORTS_EGL:tl} == "no"
MESON_ARGS+=	-Degl-x11=disabled
.  endif
.include "../../graphics/MesaLib/buildlink3.mk"
.elif !empty(PKG_OPTIONS:Mrpi)
TOOL_DEPENDS+=		raspberrypi-userland>=20170109:../../misc/raspberrypi-userland
CFLAGS+=		"-L${PREFIX}/lib"
SUBST_CLASSES+=		vc
SUBST_STAGE.vc=		pre-configure
SUBST_MESSAGE.vc=	Fixing path to VideoCore libraries.
SUBST_FILES.vc+=	meson.build
SUBST_SED.vc+=		-e 's;opt/vc;${PREFIX};g'
.endif

###
### X11 support (video output)
###
.if !empty(PKG_OPTIONS:Mx11)
MESON_ARGS+=	-Dx11=enabled
MESON_ARGS+=	-Dxv=enabled
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXpresent/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.else
MESON_ARGS+=	-Dx11=disabled
MESON_ARGS+=	-Dxv=disabled
.endif

###
### Sixel support (video output)
###
.if !empty(PKG_OPTIONS:Msixel)
MESON_ARGS+=	-Dsixel=enabled
.include "../../graphics/libsixel/buildlink3.mk"
.else
MESON_ARGS+=	-Dsixel=disabled
.endif
