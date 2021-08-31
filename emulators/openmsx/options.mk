# $NetBSD: options.mk,v 1.1 2021/08/31 10:57:08 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.openmsx
PKG_SUPPORTED_OPTIONS=	opengl theora

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} == "Linux"
PKG_SUPPORTED_OPTIONS+=	alsa
PKG_SUGGESTED_OPTIONS=	alsa opengl theora
.else
PKG_SUGGESTED_OPTIONS=	opengl theora
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
MESON_ARGS+=	-Dalsamidi=enabled
.  include "../../audio/alsa-lib/buildlink3.mk"
.else
MESON_ARGS+=	-Dalsamidi=disabled
.endif

.if !empty(PKG_OPTIONS:Mopengl)
MESON_ARGS+=	-Dglrenderer=enabled
.  include "../../graphics/glew/buildlink3.mk"
.else
MESON_ARGS+=	-Dglrenderer=disabled
.endif

.if !empty(PKG_OPTIONS:Mtheora)
MESON_ARGS+=	-Dlaserdisc=enabled
.  include "../../audio/libvorbis/buildlink3.mk"
.  include "../../multimedia/libogg/buildlink3.mk"
.  include "../../multimedia/libtheora/buildlink3.mk"
.else
MESON_ARGS+=	-Dlaserdisc=disabled
.endif
