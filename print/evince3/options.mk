# $NetBSD: options.mk,v 1.3 2013/05/15 14:57:35 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.evince
PKG_SUPPORTED_OPTIONS=	dbus djvu dvi gnome-keyring xps
PKG_SUGGESTED_OPTIONS=	dbus gnome-keyring

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		${PKG_SUPPORTED_OPTIONS}

.if !empty(PKG_OPTIONS:Mdbus)
PLIST.dbus=		yes
.include "../../sysutils/dbus/buildlink3.mk"
BUILDLINK_API_DEPENDS.dbus-glib+=       dbus-glib>=0.70
.include "../../sysutils/dbus-glib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-dbus
.endif

.if !empty(PKG_OPTIONS:Mgnome-keyring)
.include "../../security/libgnome-keyring/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-keyring
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

.if !empty(PKG_OPTIONS:Mxps)
PLIST.xps=		yes
.include "../../print/libgxps/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-xps
.endif
