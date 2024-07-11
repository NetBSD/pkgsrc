# $NetBSD: options.mk,v 1.10 2024/07/11 19:50:51 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gd
PKG_SUPPORTED_OPTIONS=	libimagequant raqm tiff x11
PKG_SUGGESTED_OPTIONS=	libimagequant raqm tiff

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlibimagequant)
.include "../../graphics/libimagequant/buildlink3.mk"
CONFIGURE_ARGS+=	--with-liq=${BUILDLINK_PREFIX.libimagequant}
.else
CONFIGURE_ARGS+=	--without-liq
.endif

.if !empty(PKG_OPTIONS:Mraqm)
.include "../../graphics/raqm/buildlink3.mk"
CONFIGURE_ARGS+=	--with-raqm=${BUILDLINK_PREFIX.raqm}
.else
CONFIGURE_ARGS+=	--without-raqm
.endif

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
