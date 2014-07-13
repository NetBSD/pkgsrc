# $NetBSD: options.mk,v 1.1 2014/07/13 10:10:56 obache Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libsixel
PKG_SUPPORTED_OPTIONS=	curl gd gdk-pixbuf2

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcurl)
CONFIGURE_ARGS+=	--with-libcurl
.include "../../www/curl/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-libcurl
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
