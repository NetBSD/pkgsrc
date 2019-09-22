# $NetBSD: options.mk,v 1.1 2019/09/22 23:28:55 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.dosbox-x
PKG_SUPPORTED_OPTIONS=		alsa ffmpeg opengl x11
PKG_SUGGESTED_OPTIONS.Linux=	alsa
PKG_SUGGESTED_OPTIONS=		ffmpeg opengl

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} != "Darwin"
PKG_SUGGESTED_OPTIONS+=		x11
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
CONFIGURE_ARGS+=	--enable-alsa-midi
.include "../../audio/alsa-lib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-alsa-midi
.endif

.if !empty(PKG_OPTIONS:Mffmpeg)
CONFIGURE_ARGS+=	--enable-avcodec
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-avcodec
.endif

.if !empty(PKG_OPTIONS:Mopengl)
CONFIGURE_ARGS+=	--enable-opengl
.else
CONFIGURE_ARGS+=	--disable-opengl
.endif

.if !empty(PKG_OPTIONS:Mx11)
CONFIGURE_ARGS+=	--enable-x11
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libxkbfile/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-x11
.endif
