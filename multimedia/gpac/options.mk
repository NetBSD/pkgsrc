# $NetBSD: options.mk,v 1.1 2017/07/22 13:07:04 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gpac
PKG_SUPPORTED_OPTIONS=	x11
PKG_SUGGESTED_OPTIONS=	x11

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mx11)
CONFIGURE_ARGS+=	--X11-path=${X11BASE}
PLIST.x11=		yes
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"
.endif
