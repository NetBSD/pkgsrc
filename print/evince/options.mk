# $NetBSD: options.mk,v 1.9 2024/01/10 06:23:56 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.evince
PKG_SUPPORTED_OPTIONS=	dbus djvu dvi gstreamer ps tiff xps
PKG_SUGGESTED_OPTIONS=	dbus

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		${PKG_SUPPORTED_OPTIONS}

.if !empty(PKG_OPTIONS:Mdbus)
PLIST.dbus=	yes
USE_TOOLS+=	gdbus-codegen
.include "../../sysutils/dbus/buildlink3.mk"
BUILDLINK_API_DEPENDS.dbus-glib+=	dbus-glib>=0.71
.include "../../sysutils/dbus-glib/buildlink3.mk"
.else
MESON_ARGS+=	-Ddbus=false
.endif

.if !empty(PKG_OPTIONS:Mdjvu)
PLIST.djvu=	yes
.include "../../graphics/djvulibre-lib/buildlink3.mk"
.else
MESON_ARGS+=	-Ddjvu=disabled
.endif

.if !empty(PKG_OPTIONS:Mdvi)
PLIST.dvi=	yes
.include "../../print/kpathsea/buildlink3.mk"
.else
MESON_ARGS+=	-Ddvi=disabled
.endif

.if !empty(PKG_OPTIONS:Mgstreamer)
PLIST.gstreamer=	yes
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.else
MESON_ARGS+=	-Dmultimedia=disabled
.endif

.if !empty(PKG_OPTIONS:Mps)
PLIST.ps=	yes
.include "../../print/libspectre/buildlink3.mk"
MESON_ARGS+=	-Dps=enabled
.else
MESON_ARGS+=	-Dps=disabled
.endif

.if !empty(PKG_OPTIONS:Mtiff)
PLIST.tiff=		yes
.include "../../graphics/tiff/buildlink3.mk"
.else
MESON_ARGS+=	-Dtiff=disabled
.endif

.if !empty(PKG_OPTIONS:Mxps)
PLIST.xps=		yes
.include "../../print/libgxps/buildlink3.mk"
.else
MESON_ARGS+=	-Dxps=disabled
.endif
