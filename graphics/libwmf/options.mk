# $NetBSD: options.mk,v 1.1 2010/11/11 11:38:36 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libwmf
PKG_SUPPORTED_OPTIONS=	x11
PKG_SUGGESTED_OPTIONS=	x11

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		x11

.if !empty(PKG_OPTIONS:Mx11)
PLIST.x11=		yes
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.endif
