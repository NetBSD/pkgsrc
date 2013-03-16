# $NetBSD: options.mk,v 1.5 2013/03/16 22:39:20 dholland Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.GraphicsMagick
PKG_SUPPORTED_OPTIONS=	bzip2 lzma x11 jasper ghostscript wmf
PKG_SUGGESTED_OPTIONS=	bzip2 lzma x11 jasper

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	jasper x11

.if !empty(PKG_OPTIONS:Mbzip2)
.include "../../archivers/bzip2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-bzlib
.endif

.if !empty(PKG_OPTIONS:Mlzma)
.include "../../archivers/xz/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-lzma
.endif

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
.include "../../print/ghostscript/ghostscript.buildlink3.mk"
CONFIGURE_ARGS+=	--with-gslib
.else
CONFIGURE_ARGS+=	--without-gslib
.endif

.if !empty(PKG_OPTIONS:Mwmf)
.include "../../graphics/libwmf/buildlink3.mk"
CONFIGURE_ARGS+=	--with-wmf
.else
CONFIGURE_ARGS+=	--without-wmf
.endif
