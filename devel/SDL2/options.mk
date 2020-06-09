# $NetBSD: options.mk,v 1.18 2020/06/09 19:36:52 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.SDL2
PKG_OPTIONS_REQUIRED_GROUPS=	gl
PKG_SUPPORTED_OPTIONS=		alsa dbus nas jack pulseaudio wayland x11
PKG_SUGGESTED_OPTIONS.Linux=	alsa
PKG_OPTIONS_GROUP.gl=		opengl
PKG_SUGGESTED_OPTIONS+=		opengl

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} == "NetBSD" && !empty(MACHINE_ARCH:Mearm*)
PKG_OPTIONS_GROUP.gl+=	rpi
.endif

.if ${OPSYS} != "Darwin"
PKG_SUGGESTED_OPTIONS+=	x11
.endif

.include "../../devel/wayland/platform.mk"

.if ${PLATFORM_SUPPORTS_WAYLAND} == "yes"
PKG_SUGGESTED_OPTIONS+=	wayland
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

.if !empty(PKG_OPTIONS:Mjack)
.include "../../audio/jack/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-jack
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
.endif

.if !empty(PKG_OPTIONS:Mrpi)
LOWER_VENDOR=		raspberry
SUBST_CLASSES+=		vc
SUBST_STAGE.vc=		pre-configure
SUBST_MESSAGE.vc=	Fixing path to VideoCore libraries.
SUBST_FILES.vc=		configure
SUBST_SED.vc+=		-e "s;/opt/vc;${PREFIX};g"
.include "../../misc/raspberrypi-userland/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mwayland)
CONFIGURE_ARGS+=	--enable-video-wayland
.include "../../devel/wayland/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-video-wayland
.endif
