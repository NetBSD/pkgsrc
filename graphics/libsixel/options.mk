# $NetBSD: options.mk,v 1.2 2014/11/09 07:19:54 obache Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libsixel
PKG_SUPPORTED_OPTIONS=	curl gd gdk-pixbuf2 jpeg png
PKG_SUGGESTED_OPTIONS=	curl jpeg png

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcurl)
CONFIGURE_ARGS+=	--with-libcurl
.include "../../www/curl/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-libcurl
.endif

.if !empty(PKG_OPTIONS:Mjpeg)
CONFIGURE_ARGS+=	--with-jpeg
.include "../../graphics/jpeg/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-jpeg
.endif

.if !empty(PKG_OPTIONS:Mpng)
CONFIGURE_ARGS+=	--with-png
.include "../../graphics/png/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-png
.endif

.if !empty(PKG_OPTIONS:Mgd)
CONFIGURE_ARGS+=	--with-gd
.include "../../graphics/gd/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-gd
.endif

.if !empty(PKG_OPTIONS:Mgdk-pixbuf2)
CONFIGURE_ARGS+=	--with-gdk-pixbuf2
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-gdk-pixbuf2
.endif
