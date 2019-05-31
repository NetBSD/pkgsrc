# $NetBSD: options.mk,v 1.12 2019/05/31 18:11:51 maya Exp $

.include "../../mk/bsd.fast.prefs.mk"

PKG_OPTIONS_VAR=		PKG_OPTIONS.retroarch

PKG_SUPPORTED_OPTIONS+=		libdrm sdl2 sixel qt5 x11 caca
PKG_SUPPORTED_OPTIONS+=		ffmpeg freetype mbedtls
PKG_SUPPORTED_OPTIONS+=		alsa jack openal pulseaudio

.if ${OPSYS} == "Linux"
PKG_SUPPORTED_OPTIONS+=		udev
.endif

PKG_SUGGESTED_OPTIONS+=		sdl2 freetype x11
PKG_SUGGESTED_OPTIONS.Linux+=	alsa libdrm pulseaudio mbedtls udev
PKG_SUGGESTED_OPTIONS.NetBSD+=	mbedtls

PKG_OPTIONS_OPTIONAL_GROUPS+=	gl
PKG_OPTIONS_GROUP.gl+=		opengl

.if !empty(MACHINE_ARCH:M*arm*)
CONFIGURE_ARGS+=		--enable-floathard
PKG_OPTIONS_GROUP.gl+=		rpi
PKG_SUPPORTED_OPTIONS+=		simd
.endif

.if !empty(MACHINE_PLATFORM:MNetBSD-*-arm*)
PKG_SUGGESTED_OPTIONS+=		rpi
.else
PKG_SUGGESTED_OPTIONS+=		opengl
.endif

.include "../../mk/bsd.options.mk"

.if !empty(MACHINE_ARCH:M*arm*)
.  if !empty(PKG_OPTIONS:Msimd)
CONFIGURE_ARGS+=	--enable-neon
.  else
CONFIGURE_ARGS+=	--disable-neon
.  endif
.endif

.if !empty(PKG_OPTIONS:Mlibdrm)
CONFIGURE_ARGS+=	--enable-plain_drm
.include "../../x11/libdrm/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Msixel)
CONFIGURE_ARGS+=	--enable-sixel
.include "../../graphics/libsixel/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-sixel
.endif

.if !empty(PKG_OPTIONS:Mmbedtls)
CONFIGURE_ARGS+=	--enable-ssl
.include "../../security/mbedtls/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-ssl
.endif

.if !empty(PKG_OPTIONS:Mx11)
CONFIGURE_ARGS+=	--enable-x11
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-x11
.endif

#
# Graphics acceleration options
#

# Use standard Mesa OpenGL
.if !empty(PKG_OPTIONS:Mopengl)
.include "../../graphics/MesaLib/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-opengl

# Enable use of the Raspberry Pi GPU driver
.elif !empty(PKG_OPTIONS:Mrpi)
.include "../../misc/raspberrypi-userland/buildlink3.mk"
SUBST_CLASSES+=		vc
SUBST_STAGE.vc=		pre-configure
SUBST_MESSAGE.vc=	Fixing path to VideoCore libraries.
SUBST_FILES.vc=		qb/config.libs.sh
SUBST_SED.vc+=		-e 's;/opt/vc;${PREFIX};g'

CONFIGURE_ARGS+=	--enable-opengles

# Disable any graphics acceleration library
.else
CONFIGURE_ARGS+=	--disable-egl
CONFIGURE_ARGS+=	--disable-opengl
CONFIGURE_ARGS+=	--disable-vulkan
CONFIGURE_ARGS+=	--disable-vulkan_display
CONFIGURE_ARGS+=	--disable-wayland
.endif

.if !empty(PKG_OPTIONS:Mudev)
# To support keyboard callback interface in udev, the libxkbcommon package
# (version 0.3 and up) is required. It is used to translate raw evdev events
# to printable characters. It does not depend on Xorg, but it depends on X11
# keyboard layout files being installed.
.include "../../x11/libxkbcommon/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-udev
.endif

.if !empty(PKG_OPTIONS:Msdl2)
CONFIGURE_ARGS+=	--enable-sdl2
.include "../../devel/SDL2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-sdl2
.endif

.if !empty(PKG_OPTIONS:Mffmpeg)
CONFIGURE_ARGS+=	--enable-ffmpeg
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-ffmpeg
.endif

.if !empty(PKG_OPTIONS:Mfreetype)
CONFIGURE_ARGS+=	--enable-freetype
.include "../../graphics/freetype2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-freetype
.endif

.if !empty(PKG_OPTIONS:Malsa)
CONFIGURE_ARGS+=	--enable-alsa
.include "../../audio/alsa-lib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-alsa
.endif

.if !empty(PKG_OPTIONS:Mjack)
CONFIGURE_ARGS+=	--enable-jack
.include "../../audio/jack/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-jack
.endif

.if !empty(PKG_OPTIONS:Mopenal)
CONFIGURE_ARGS+=	--enable-al
.include "../../audio/openal-soft/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-al
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
CONFIGURE_ARGS+=	--enable-pulse
.include "../../audio/pulseaudio/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-pulse
.endif

.if !empty(PKG_OPTIONS:Mqt5)
.include "../../x11/qt5-qtbase/buildlink3.mk"
# error: "You must build your code with position independent code if Qt was built with -reduce-relocations."
CFLAGS+=		-fPIC
CONFIGURE_ENV+=		MOC=${QTDIR}/bin/moc
CONFIGURE_ARGS+=	--enable-qt
.else
CONFIGURE_ARGS+=	--disable-qt
.endif

.if !empty(PKG_OPTIONS:Mcaca)
CONFIGURE_ARGS+=	--enable-caca
.include "../../graphics/libcaca/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-caca
.endif
