# $NetBSD: options.mk,v 1.6 2019/04/26 13:14:00 maya Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.eog
PKG_SUPPORTED_OPTIONS=	dbus exif jpeg lcms rsvg xmp
PKG_SUGGESTED_OPTIONS=	dbus exif jpeg lcms rsvg xmp

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

# The python option is logically impossible right now.  This option sets python
# 3.x as being incompatible, yet eom depends on libpeas which itself sets 2.x
# as being incompatible, leaving us with no remaining choices.
.if !empty(PKG_OPTIONS:Mpython)
PYTHON_VERSIONS_INCOMPATIBLE=	 36 37 # py-gtk2
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
