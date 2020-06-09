# $NetBSD: options.mk,v 1.2 2020/06/09 12:22:01 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.freerdp2
PKG_SUPPORTED_OPTIONS=		alsa pulseaudio cups x11
PKG_SUGGESTED_OPTIONS=		x11
PKG_SUGGESTED_OPTIONS.Linux=	alsa

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
CMAKE_ARGS+=	-DWITH_ALSA=ON
.include "../../audio/alsa-lib/buildlink3.mk"
.else
CMAKE_ARGS+=	-DWITH_ALSA=OFF
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
CMAKE_ARGS+=	-DWITH_PULSE=ON
.include "../../audio/pulseaudio/buildlink3.mk"
.else
CMAKE_ARGS+=	-DWITH_PULSE=OFF
.endif

.if !empty(PKG_OPTIONS:Mcups)
CMAKE_ARGS+=	-DWITH_CUPS=ON
.include "../../print/libcups/buildlink3.mk"
.else
CMAKE_ARGS+=	-DWITH_CUPS=OFF
.endif

PLIST_VARS+=	x11
.if !empty(PKG_OPTIONS:Mx11)
PLIST.x11=	yes
CMAKE_ARGS+=	-DWITH_X11=ON
.include "../../x11/libxkbfile/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"
.else
CMAKE_ARGS+=	-DWITH_X11=OFF
.endif
