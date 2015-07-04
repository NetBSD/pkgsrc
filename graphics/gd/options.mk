# $NetBSD: options.mk,v 1.4 2015/07/04 16:18:35 joerg Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gd
PKG_SUPPORTED_OPTIONS=	libvpx x11
PKG_SUGGESTED_OPTIONS=	libvpx

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mx11)
.include "../../x11/libXpm/buildlink3.mk"
CONFIGURE_ENV+=		X11BASE=${X11BASE}
CONFIGURE_ARGS+=	--with-xpm=${BUILDLINK_PREFIX.libXpm}
.else
CONFIGURE_ARGS+=	--without-xpm
.endif

.if !empty(PKG_OPTIONS:Mlibvpx)
.include "../../multimedia/libvpx/buildlink3.mk"
CONFIGURE_ARGS+=	--with-vpx=${BUILDLINK_PREFIX.libvpx}
.else
CONFIGURE_ARGS+=	--without-vpx
.endif
