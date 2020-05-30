# $NetBSD: options.mk,v 1.14 2020/05/30 14:26:52 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.retroarch

PKG_SUPPORTED_OPTIONS+=		alsa jack openal pulseaudio
PKG_SUPPORTED_OPTIONS+=		debug caca ffmpeg freetype sixel qt5

.include "../../mk/bsd.fast.prefs.mk"

PKG_OPTIONS_OPTIONAL_GROUPS+=	gl

.if ${OPSYS} == "NetBSD" && !empty(MACHINE_ARCH:M*arm*)
PKG_OPTIONS_GROUP.gl+=		rpi
.endif

.if ${OPSYS} != "Darwin"
PKG_OPTIONS_GROUP.gl+=		opengl
PKG_SUGGESTED_OPTIONS=		freetype opengl
.else
PKG_SUGGESTED_OPTIONS=		freetype
.endif

PKG_SUGGESTED_OPTIONS.Linux+=	alsa pulseaudio

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if !empty(PKG_OPTIONS:Msixel)
CONFIGURE_ARGS+=	--enable-sixel
.include "../../graphics/libsixel/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-sixel
.endif

#
# Graphics acceleration options
#

# Use standard Mesa OpenGL
.if !empty(PKG_OPTIONS:Mopengl)
CONFIGURE_ARGS+=	--enable-opengl
.include "../../graphics/MesaLib/buildlink3.mk"

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
.elif ${OPSYS} != "Darwin"
CONFIGURE_ARGS+=	--disable-egl
CONFIGURE_ARGS+=	--disable-opengl
CONFIGURE_ARGS+=	--disable-opengl_core
CONFIGURE_ARGS+=	--disable-vulkan
CONFIGURE_ARGS+=	--disable-vulkan_display
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
