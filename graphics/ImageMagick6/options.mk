# $NetBSD: options.mk,v 1.1 2016/05/25 12:41:17 ryoon Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ImageMagick
PKG_SUPPORTED_OPTIONS=	x11 jasper djvu openexr wmf
PKG_SUGGESTED_OPTIONS=	x11 jasper

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mx11)
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-x
.endif

.if !empty(PKG_OPTIONS:Mjasper)
BUILDLINK_API_DEPENDS.jasper+=	jasper>=1.701.0
.include "../../graphics/jasper/buildlink3.mk"
CONFIGURE_ARGS+=	--with-jp2
.else
CONFIGURE_ARGS+=	--without-jp2
.endif

.if !empty(PKG_OPTIONS:Mdjvu)
.include "../../graphics/djvulibre-lib/buildlink3.mk"
CONFIGURE_ARGS+=	--with-djvu
.else
CONFIGURE_ARGS+=	--without-djvu
.endif

.if !empty(PKG_OPTIONS:Mopenexr)
.include "../../graphics/openexr/buildlink3.mk"
CONFIGURE_ARGS+=	--with-openexr
.else
CONFIGURE_ARGS+=	--without-openexr
.endif

.if !empty(PKG_OPTIONS:Mwmf)
.include "../../graphics/libwmf/buildlink3.mk"
CONFIGURE_ARGS+=	--with-wmf
.else
CONFIGURE_ARGS+=	--without-wmf
.endif
