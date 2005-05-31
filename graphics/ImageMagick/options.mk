# $NetBSD: options.mk,v 1.2 2005/05/31 10:01:36 dillo Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ImageMagick
PKG_SUPPORTED_OPTIONS=	x11
PKG_SUGGESTED_OPTIONS=	x11

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mx11)
BUILDLINK_DEPENDS.jasper+= jasper>=1.701.0
DEPENDS+=		mpeg2codec-1.2:../../graphics/mpeg2codec
USE_X11=		YES

.include "../../graphics/jasper/buildlink3.mk"
.include "../../graphics/libwmf/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-x
.endif
