# $NetBSD: options.mk,v 1.1 2016/08/13 17:34:41 taca Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gd
PKG_SUPPORTED_OPTIONS=	x11

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mx11)
.include "../../x11/libXpm/buildlink3.mk"
CONFIGURE_ENV+=		X11BASE=${X11BASE}
CONFIGURE_ARGS+=	--with-xpm-dir=${BUILDLINK_PREFIX.libXpm}
.else
CONFIGURE_ARGS+=	--with-xpm-dir=no
.endif
