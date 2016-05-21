# $NetBSD: options.mk,v 1.1 2016/05/21 19:20:33 youri Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.eog
PKG_SUPPORTED_OPTIONS=	dbus exif jpeg lcms python rsvg xmp
PKG_SUGGESTED_OPTIONS=	dbus exif jpeg lcms python rsvg xmp

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdbus)
.include "../../sysutils/dbus-glib/buildlink3.mk"
CONFIGURE_ARGS+=	--with-dbus
.else
CONFIGURE_ARGS+=	--without-dbus
.endif

.if !empty(PKG_OPTIONS:Mexif)
.include "../../graphics/libexif/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libexif
.else
CONFIGURE_ARGS+=	--without-libexif
.endif

.if !empty(PKG_OPTIONS:Mjpeg)
.include "../../mk/jpeg.buildlink3.mk"
CONFIGURE_ARGS+=	--with-libjpeg
.else
CONFIGURE_ARGS+=	--without-libjpeg
.endif

.if !empty(PKG_OPTIONS:Mlcms)
.include "../../graphics/lcms2/buildlink3.mk"
CONFIGURE_ARGS+=	--with-cms
.include "../../graphics/libexif/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-cms
.endif

.if !empty(PKG_OPTIONS:Mpython)
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # py-gtk2
.include "../../lang/python/extension.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../devel/py-gobject/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-python
.else
CONFIGURE_ARGS+=	--disable-python
.endif

.if !empty(PKG_OPTIONS:Mrsvg)
.include "../../graphics/librsvg/buildlink3.mk"
CONFIGURE_ARGS+=	--with-librsvg
.else
CONFIGURE_ARGS+=	--without-librsvg
.endif

.if !empty(PKG_OPTIONS:Mxmp)
.include "../../devel/exempi/buildlink3.mk"
CONFIGURE_ARGS+=	--with-xmp
.else
CONFIGURE_ARGS+=	--without-xmp
.endif
