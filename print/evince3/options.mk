# $NetBSD: options.mk,v 1.6 2016/02/26 02:24:34 leot Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.evince
PKG_SUPPORTED_OPTIONS=	dbus djvu dvi gstreamer xps
PKG_SUGGESTED_OPTIONS=	dbus

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		${PKG_SUPPORTED_OPTIONS}

.if !empty(PKG_OPTIONS:Mdbus)
PLIST.dbus=		yes
.include "../../sysutils/dbus/buildlink3.mk"
BUILDLINK_API_DEPENDS.dbus-glib+=	dbus-glib>=0.70
.include "../../sysutils/dbus-glib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-dbus
.endif

.if !empty(PKG_OPTIONS:Mdvi)
PLIST.dvi=		yes
.include "../../print/kpathsea/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-dvi
.endif

.if !empty(PKG_OPTIONS:Mdjvu)
PLIST.djvu=		yes
.include "../../graphics/djvulibre-lib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-djvu
.endif

.if !empty(PKG_OPTIONS:Mgstreamer)
PLIST.gstreamer=	yes
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-multimedia
.endif

.if !empty(PKG_OPTIONS:Mxps)
PLIST.xps=		yes
.include "../../print/libgxps/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-xps
.endif
