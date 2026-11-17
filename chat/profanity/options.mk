# $NetBSD: options.mk,v 1.2 2026/11/17 21:42:57 ktnb Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.profanity
PKG_SUPPORTED_OPTIONS=	libnotify gtk3 xscrnsaver
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

# gtk2
.if !empty(PKG_OPTIONS:Mgtk3)
MESON_ARGS+=		-Dicons-and-clipboard=enabled
.include "../../x11/gtk3/buildlink3.mk"
.endif

# libnotify
.if !empty(PKG_OPTIONS:Mlibnotify)
MESON_ARGS+=		-Dnotifications=enabled
.include "../../sysutils/libnotify/buildlink3.mk"
.endif

# xscrnsaver
.if !empty(PKG_OPTIONS:Mxscrnsaver)
MESON_ARGS+=		-Dxscreensaver=enabled
.include "../../x11/libXScrnSaver/buildlink3.mk"
.endif
