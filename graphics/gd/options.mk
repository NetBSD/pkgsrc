# $NetBSD: options.mk,v 1.8 2018/09/10 13:34:16 kim Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gd
PKG_SUPPORTED_OPTIONS=	tiff x11
PKG_SUGGESTED_OPTIONS=	tiff

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mtiff)
.include "../../graphics/tiff/buildlink3.mk"
CONFIGURE_ARGS+=	--with-tiff=${BUILDLINK_PREFIX.tiff}
.else
CONFIGURE_ARGS+=	--without-tiff
.endif

.if !empty(PKG_OPTIONS:Mx11)
.include "../../x11/libXpm/buildlink3.mk"
CONFIGURE_ENV+=		X11BASE=${X11BASE}
CONFIGURE_ARGS+=	--with-xpm=${BUILDLINK_PREFIX.libXpm}
.else
CONFIGURE_ARGS+=	--without-xpm
.endif
