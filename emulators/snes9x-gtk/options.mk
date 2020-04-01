# $NetBSD: options.mk,v 1.4 2020/04/01 10:08:15 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.snes9x-gtk
PKG_SUPPORTED_OPTIONS=		alsa opengl pulseaudio portaudio wayland

PKG_OPTIONS_REQUIRED_GROUPS=	gtk
PKG_OPTIONS_GROUP.gtk=		gtk2 gtk3

PKG_SUGGESTED_OPTIONS+=		gtk3 opengl
PKG_SUGGESTED_OPTIONS.Linux+=	alsa

.include "../../mk/oss.buildlink3.mk"

.if ${OPSYS} != "Linux" && ${OSS_TYPE} == "none"
PKG_SUGGESTED_OPTIONS+=		portaudio
.endif

.include "../../devel/wayland/platform.mk"

.if ${PLATFORM_SUPPORTS_WAYLAND} == "yes"
PKG_SUGGESTED_OPTIONS+=		wayland
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
.include "../../audio/alsa-lib/buildlink3.mk"
.else
MESON_ARGS+=	-Dalsa=false
.endif

.if !empty(PKG_OPTIONS:Mgtk2)
.include "../../x11/gtk2/buildlink3.mk"
MESON_ARGS+=	-Dgtk2=true
.else
MESON_ARGS+=	-Dgtk2=false
.endif

.if !empty(PKG_OPTIONS:Mgtk3)
.include "../../x11/gtk3/buildlink3.mk"
MESON_ARGS+=	-Dgtk3=true
.else
MESON_ARGS+=	-Dgtk3=false
.endif

.if !empty(PKG_OPTIONS:Mopengl)
.include "../../graphics/MesaLib/buildlink3.mk"
MESON_ARGS+=	-Dopengl=true
.else
MESON_ARGS+=	-Dopengl=false
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
.include "../../audio/pulseaudio/buildlink3.mk"
MESON_ARGS+=	-Dpulseaudio=true
.else
MESON_ARGS+=	-Dpulseaudio=false
.endif

.if !empty(PKG_OPTIONS:Mportaudio)
.include "../../audio/portaudio/buildlink3.mk"
MESON_ARGS+=	-Dportaudio=true
.else
MESON_ARGS+=	-Dportaudio=false
.endif

.if !empty(PKG_OPTIONS:Mwayland)
.include "../../devel/wayland/buildlink3.mk"
MESON_ARGS+=	-Dwayland=true
.else
MESON_ARGS+=	-Dwayland=false
.endif
