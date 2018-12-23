# $NetBSD: options.mk,v 1.8 2018/12/23 14:27:15 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.SDL2
PKG_OPTIONS_REQUIRED_GROUPS=	gl
PKG_SUPPORTED_OPTIONS=	alsa dbus esound nas oss pulseaudio x11
PKG_OPTIONS_GROUP.gl=	opengl
PKG_SUGGESTED_OPTIONS+=	oss

.if ${OPSYS} != "Darwin"
PKG_SUGGESTED_OPTIONS+=	x11
.endif

.include "../../mk/bsd.fast.prefs.mk"

.if !empty(MACHINE_ARCH:M*arm*)
PKG_OPTIONS_GROUP.gl+= rpi
PKG_SUGGESTED_OPTIONS+=	rpi
.else
PKG_SUGGESTED_OPTIONS+=	opengl
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
.include "../../audio/alsa-lib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-alsa
.endif

.if !empty(PKG_OPTIONS:Mdbus)
.include "../../sysutils/dbus/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-dbus
.endif

.if !empty(PKG_OPTIONS:Mesound)
.include "../../audio/esound/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mnas)
.include "../../audio/nas/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-nas
.endif

.if !empty(PKG_OPTIONS:Mopengl)
.  if ${OPSYS} != "Darwin"
.include "../../graphics/MesaLib/buildlink3.mk"
.  endif
.else
CONFIGURE_ARGS+=	--disable-video-opengl
.endif

.if !empty(PKG_OPTIONS:Moss)
.include "../../mk/oss.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-oss
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
.include "../../audio/pulseaudio/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-pulseaudio
.endif

.if !empty(PKG_OPTIONS:Mx11)
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-video-x11
CONFIGURE_ARGS+=	--disable-x11-shared
.endif

.if !empty(PKG_OPTIONS:Mrpi)
LOWER_VENDOR=		raspberry
# fails to produce shared libraries
# try standard GLES instead
CONFIGURE_ARGS+=	--disable-video-rpi
CONFIGURE_ARGS+=	--enable-video-opengles
CONFIGURE_ARGS+=	--enable-video-opengles1
CONFIGURE_ARGS+=	--enable-video-opengles2
SUBST_CLASSES+=		gles
SUBST_STAGE.gles=	pre-configure
SUBST_MESSAGE.gles=	Fixing name of GLES library.
SUBST_FILES.gles=	src/video/SDL_egl.c
SUBST_SED.gles+=	-e 's/libGLESv2.so.2/libGLESv2.so/g'
.include "../../misc/raspberrypi-userland/buildlink3.mk"
.endif
