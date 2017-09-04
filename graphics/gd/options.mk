# $NetBSD: options.mk,v 1.7 2017/09/04 06:20:45 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gd
PKG_SUPPORTED_OPTIONS=	x11

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mx11)
.include "../../x11/libXpm/buildlink3.mk"
CONFIGURE_ENV+=		X11BASE=${X11BASE}
CONFIGURE_ARGS+=	--with-xpm=${BUILDLINK_PREFIX.libXpm}
.else
CONFIGURE_ARGS+=	--without-xpm
.endif
