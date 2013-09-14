# $NetBSD: options.mk,v 1.1 2013/09/14 09:13:26 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gifsicle
PKG_SUPPORTED_OPTIONS=	x11
PKG_SUGGESTED_OPTIONS=	x11

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		x11

.if !empty(PKG_OPTIONS:Mx11)
BUILDLINK_DEPMETHOD.libXt+=	build
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
PLIST.x11=		yes
.else
CONFIGURE_ARGS+=	--disable-gifview
.endif
