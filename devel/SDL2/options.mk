# $NetBSD: options.mk,v 1.1 2013/08/15 10:26:16 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.SDL2
PKG_SUPPORTED_OPTIONS=	alsa arts esound nas opengl oss pulseaudio
PKG_SUPPORTED_OPTIONS+=	x11 xcursor xim xinerama xrandr xrender xscrnsaver
PKG_SUGGESTED_OPTIONS+=	oss

.if ${OPSYS} == "Darwin"
PKG_SUGGESTED_OPTIONS+=	opengl
.else
PKG_SUGGESTED_OPTIONS+=	x11
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
.include "../../audio/alsa-lib/buildlink3.mk"
CMAKE_ARGS+=		-DALSA=ON
.else
CMAKE_ARGS+=		-DALSA=OFF
.endif

.if !empty(PKG_OPTIONS:Marts)
.include "../../audio/arts/buildlink3.mk"
CMAKE_ARGS+=		-DARTS=ON
.else
CMAKE_ARGS+=		-DARTS=OFF
.endif

.if !empty(PKG_OPTIONS:Mesound)
.include "../../audio/esound/buildlink3.mk"
CMAKE_ARGS+=		-DESD=ON
.else
CMAKE_ARGS+=		-DESD=OFF
.endif

.if !empty(PKG_OPTIONS:Mnas)
.include "../../audio/nas/buildlink3.mk"
CMAKE_ARGS+=		-DNAS=ON
.else
CMAKE_ARGS+=		-DNAS=OFF
.endif

.if !empty(PKG_OPTIONS:Mopengl)
.  if ${OPSYS} != "Darwin"
.include "../../graphics/MesaLib/buildlink3.mk"
.  endif
CMAKE_ARGS+=		-DVIDEO_OPENGL=ON
.else
CMAKE_ARGS+=		-DVIDEO_OPENGL=OFF
.endif

.if !empty(PKG_OPTIONS:Moss)
CMAKE_ARGS+=		-DOSS=ON
.else
CMAKE_ARGS+=		-DOSS=OFF
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
.include "../../audio/pulseaudio/buildlink3.mk"
CMAKE_ARGS+=		-DPULSEAUDIO=ON
.else
CMAKE_ARGS+=		-DPULSEAUDIO=OFF
.endif

.if !empty(PKG_OPTIONS:Mx11)
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
CMAKE_ARGS+=		-DX11_SHARED=ON -DVIDEO_X11=ON
.else
CMAKE_ARGS+=		-DX11_SHARED=OFF -DVIDEO_X11=OFF
.endif

.if !empty(PKG_OPTIONS:Mxcursor)
.include "../../x11/libXcursor/buildlink3.mk"
CMAKE_ARGS+=		-DVIDEO_X11_XCURSOR=ON
.else
CMAKE_ARGS+=		-DVIDEO_X11_XCURSOR=OFF
.endif

.if !empty(PKG_OPTIONS:Mxim)
.include "../../x11/libXi/buildlink3.mk"
CMAKE_ARGS+=		-DVIDEO_X11_XINPUT=ON
.else
CMAKE_ARGS+=		-DVIDEO_X11_XINPUT=OFF
.endif

.if !empty(PKG_OPTIONS:Mxinerama)
.include "../../x11/libXinerama/buildlink3.mk"
CMAKE_ARGS+=		-DVIDEO_X11_XINERAMA=ON
.else
CMAKE_ARGS+=		-DVIDEO_X11_XINERAMA=OFF
.endif

.if !empty(PKG_OPTIONS:Mxrandr)
.include "../../x11/libXrandr/buildlink3.mk"
CMAKE_ARGS+=		-DVIDEO_X11_XRANDR=ON
.else
CMAKE_ARGS+=		-DVIDEO_X11_XRANDR=OFF
.endif

.if !empty(PKG_OPTIONS:Mxrender)
.include "../../x11/libXrender/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mxscrnsaver)
.include "../../x11/libXScrnSaver/buildlink3.mk"
CMAKE_ARGS+=		-DVIDEO_X11_XSCRNSAVER=ON
.else
CMAKE_ARGS+=		-DVIDEO_X11_XSCRNSAVER=OFF
.endif
