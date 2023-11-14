# $NetBSD: options.mk,v 1.5 2023/11/14 13:58:36 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.atril
PKG_SUPPORTED_OPTIONS=	dbus pdf ps xps dvi djvu tiff gdk-pixbuf keyring introspection
PKG_SUGGESTED_OPTIONS=	dbus pdf ps xps djvu tiff gdk-pixbuf keyring

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	dbus pdf ps xps dvi djvu tiff pixbuf introspection

.if !empty(PKG_OPTIONS:Mdbus)
.include "../../sysutils/dbus-glib/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-dbus
PLIST.dbus=	yes
.else
CONFIGURE_ARGS+=	--disable-dbus
.endif

.if !empty(PKG_OPTIONS:Mps)
.include "../../print/libspectre/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-ps
PLIST.ps=	yes
.else
CONFIGURE_ARGS+=	--disable-ps
.endif

.if !empty(PKG_OPTIONS:Mxps)
.include "../../print/libgxps/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-xps
PLIST.xps=	yes
.else
CONFIGURE_ARGS+=	--disable-xps
.endif

.if !empty(PKG_OPTIONS:Mpdf)
.include "../../print/poppler-glib/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-pdf
PLIST.pdf=	yes
.else
CONFIGURE_ARGS+=	--disable-pdf
.endif

.if !empty(PKG_OPTIONS:Mdvi)
.include "../../print/kpathsea/buildlink3.mk"
.include "../../fonts/t1lib/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-dvi
CONFIGURE_ARGS+=	--enable-t1lib
PLIST.dvi=	yes
.else
CONFIGURE_ARGS+=	--disable-dvi
CONFIGURE_ARGS+=	--disable-t1lib
.endif

.if !empty(PKG_OPTIONS:Mdjvu)
.include "../../graphics/djvulibre-lib/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-djvu
PLIST.djvu=	yes
.else
CONFIGURE_ARGS+=	--disable-djvu
.endif

.if !empty(PKG_OPTIONS:Mtiff)
.include "../../graphics/tiff/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-tiff
PLIST.tiff=	yes
.else
CONFIGURE_ARGS+=	--disable-tiff
.endif

.if !empty(PKG_OPTIONS:Mgdk-pixbuf)
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-pixbuf
PLIST.pixbuf=yes
.else
CONFIGURE_ARGS+=	--disable-pixbuf
.endif

.if !empty(PKG_OPTIONS:Mkeyring)
.include "../../security/libsecret/buildlink3.mk"
CONFIGURE_ARGS+=	--with-keyring
.else
CONFIGURE_ARGS+=	--without-keyring
.endif

.if !empty(PKG_OPTIONS:Mintrospection)
BUILDLINK_DEPMETHOD.gobject-introspection+=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.18
.include "../../graphics/cairo/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-introspection
PLIST.introspection=	yes
.else
CONFIGURE_ARGS+=	--disable-introspection
.endif
