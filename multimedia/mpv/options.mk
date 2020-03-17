# $NetBSD: options.mk,v 1.24 2020/03/17 11:22:31 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mpv


PKG_OPTIONS_OPTIONAL_GROUPS=	gl
PKG_OPTIONS_GROUP.gl=		opengl rpi

# audio outputs
PKG_SUPPORTED_OPTIONS+=		alsa jack pulseaudio
# video outputs
PKG_SUPPORTED_OPTIONS+=		caca libdrm wayland x11
# audio/video outputs
PKG_SUPPORTED_OPTIONS+=		sdl2
# misc
PKG_SUPPORTED_OPTIONS+=		ass bluray lua

PKG_SUGGESTED_OPTIONS=		ass bluray lua sdl2
PKG_SUGGESTED_OPTIONS.Linux+=	alsa pulseaudio

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} != "Darwin"
PKG_SUGGESTED_OPTIONS+=		opengl libdrm x11
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

.include "../../devel/wayland/platform.mk"

.if ${PLATFORM_SUPPORTS_WAYLAND} == "yes"
PKG_SUGGESTED_OPTIONS+=		wayland
.endif

.include "../../mk/bsd.options.mk"

###
### alsa support (audio output)
###
.if !empty(PKG_OPTIONS:Malsa)
WAF_CONFIGURE_ARGS+=	--enable-alsa
.include "../../audio/alsa-lib/buildlink3.mk"
.else
WAF_CONFIGURE_ARGS+=	--disable-alsa
.endif

###
### libbluray support
###
.if !empty(PKG_OPTIONS:Mbluray)
WAF_CONFIGURE_ARGS+=	--enable-libbluray
.include "../../multimedia/libbluray/buildlink3.mk"
.else
WAF_CONFIGURE_ARGS+=	--disable-libbluray
.endif

###
### caca support (video output)
###
.if !empty(PKG_OPTIONS:Mcaca)
WAF_CONFIGURE_ARGS+=	--enable-caca
.include "../../graphics/libcaca/buildlink3.mk"
.else
WAF_CONFIGURE_ARGS+=	--disable-caca
.endif

###
### lua support
###
.if !empty(PKG_OPTIONS:Mlua)
WAF_CONFIGURE_ARGS+=	--enable-lua
LUA_VERSIONS_INCOMPATIBLE=	53
.include "../../lang/lua/buildlink3.mk"
.else
WAF_CONFIGURE_ARGS+=	--disable-lua
.endif

###
### JACK support (audio output)
###
.if !empty(PKG_OPTIONS:Mjack)
WAF_CONFIGURE_ARGS+=	--enable-jack
.include "../../audio/jack/buildlink3.mk"
.else
WAF_CONFIGURE_ARGS+=	--disable-jack
.endif

###
### PulseAudio support (audio output)
###
.if !empty(PKG_OPTIONS:Mpulseaudio)
WAF_CONFIGURE_ARGS+=	--enable-pulse
.include "../../audio/pulseaudio/buildlink3.mk"
.else
WAF_CONFIGURE_ARGS+=	--disable-pulse
.endif

###
### SDL2 support (audio and video output)
###
.if !empty(PKG_OPTIONS:Msdl2)
WAF_CONFIGURE_ARGS+=	--enable-sdl2
.include "../../devel/SDL2/buildlink3.mk"
.else
WAF_CONFIGURE_ARGS+=	--disable-sdl2
.endif

###
### libASS support
###
.if !empty(PKG_OPTIONS:Mass)
WAF_CONFIGURE_ARGS+=	--enable-libass
.include "../../multimedia/libass/buildlink3.mk"
.else
WAF_CONFIGURE_ARGS+=	--disable-libass
.endif

###
### VAAPI support (video output)
###
.if !empty(PKG_OPTIONS:Mvaapi)
WAF_CONFIGURE_ARGS+=	--enable-vaapi
.include "../../multimedia/libva/buildlink3.mk"
.else
WAF_CONFIGURE_ARGS+=	--disable-vaapi
.endif

###
### VDPAU support (video output)
###
.if !empty(PKG_OPTIONS:Mvdpau)
WAF_CONFIGURE_ARGS+=	--enable-vdpau
.include "../../multimedia/libvdpau/buildlink3.mk"
.else
WAF_CONFIGURE_ARGS+=	--disable-vdpau
.endif

###
### libdrm support (video output)
###
.if !empty(PKG_OPTIONS:Mlibdrm)
WAF_CONFIGURE_ARGS+=	--enable-drm
.include "../../x11/libdrm/buildlink3.mk"
.else
WAF_CONFIGURE_ARGS+=	--disable-drm
.endif

###
### OpenGL support (video output)
###
.if !empty(PKG_OPTIONS:Mopengl)
.include "../../graphics/MesaLib/buildlink3.mk"
.elif !empty(PKG_OPTIONS:Mrpi)
BUILD_DEPENDS+=		raspberrypi-userland>=20170109:../../misc/raspberrypi-userland
CFLAGS+=		"-L${PREFIX}/lib"
SUBST_CLASSES+=		vc
SUBST_STAGE.vc=		pre-configure
SUBST_MESSAGE.vc=	Fixing path to VideoCore libraries.
SUBST_FILES.vc=		waftools/checks/custom.py
SUBST_SED.vc+=		-e 's;opt/vc;${PREFIX};g'
.endif

###
### Wayland support (video output)
###
.if !empty(PKG_OPTIONS:Mwayland)
WAF_CONFIGURE_ARGS+=	--enable-wayland
.include "../../devel/wayland/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.else
WAF_CONFIGURE_ARGS+=	--disable-wayland
.endif

###
### X11 support (video output)
###
.if !empty(PKG_OPTIONS:Mx11)
WAF_CONFIGURE_ARGS+=	--enable-x11
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.else
WAF_CONFIGURE_ARGS+=	--disable-x11
.endif
