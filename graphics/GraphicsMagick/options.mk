# $NetBSD: options.mk,v 1.10 2020/05/15 13:13:40 rillig Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.GraphicsMagick
PKG_SUPPORTED_OPTIONS=	x11 jasper ghostscript wmf
PKG_SUGGESTED_OPTIONS=	x11

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	jasper x11

.if !empty(PKG_OPTIONS:Mx11)
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
PLIST.x11=		yes
.else
CONFIGURE_ARGS+=	--without-x
.endif

.if !empty(PKG_OPTIONS:Mjasper)
BUILDLINK_API_DEPENDS.jasper+=	jasper>=1.701.0
.include "../../graphics/jasper/buildlink3.mk"
CONFIGURE_ARGS+=	--with-jp2
PLIST.jasper=		yes
.else
CONFIGURE_ARGS+=	--without-jp2
.endif

.if !empty(PKG_OPTIONS:Mghostscript)
USE_TOOLS+=		gs:run
.include "../../print/ghostscript/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mwmf)
.include "../../graphics/libwmf/buildlink3.mk"
CONFIGURE_ARGS+=	--with-wmf
.else
CONFIGURE_ARGS+=	--without-wmf
.endif
