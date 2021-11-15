# $NetBSD: options.mk,v 1.1 2021/11/15 22:01:20 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.gst-plugins1-good
PKG_SUPPORTED_OPTIONS=		gtk3 jack pulseaudio x11

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} != "Darwin"
PKG_SUGGESTED_OPTIONS=		gtk3 x11
.endif

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	gtk3
.if !empty(PKG_OPTIONS:Mgtk3)
.include "../../x11/gtk3/buildlink3.mk"
CONFLICTS+=		gst-plugins1-gtk-[0-9]*
SUPERSEDES+=		gst-plugins1-gtk-[0-9]*
PLIST.gtk3=		yes
.else
MESON_ARGS+=		-D gtk3=disabled
.endif

PLIST_VARS+=	jack
.if !empty(PKG_OPTIONS:Mjack)
.include "../../audio/jack/buildlink3.mk"
CONFLICTS+=		gst-plugins1-jack-[0-9]*
SUPERSEDES+=		gst-plugins1-jack-[0-9]*
PLIST.jack=		yes
.else
MESON_ARGS+=		-D jack=disabled
.endif

PLIST_VARS+=	pulseaudio
.if !empty(PKG_OPTIONS:Mpulseaudio)
.include "../../audio/pulseaudio/buildlink3.mk"
CONFLICTS+=		gst-plugins1-pulse-[0-9]*
SUPERSEDES+=		gst-plugins1-pulse-[0-9]*
PLIST.pulseaudio=	yes
.else
MESON_ARGS+=		-D pulse=disabled
.endif

PLIST_VARS+=	x11
.if !empty(PKG_OPTIONS:Mx11)
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
PLIST.x11=		yes
.else
MESON_ARGS+=		-D ximagesrc=disabled
.endif
