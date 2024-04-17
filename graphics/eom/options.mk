# $NetBSD: options.mk,v 1.8 2024/04/17 12:00:00 wiz Exp $

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
