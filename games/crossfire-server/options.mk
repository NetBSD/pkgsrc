# $NetBSD: options.mk,v 1.2 2019/03/20 11:05:04 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.crossfire-server
PKG_SUPPORTED_OPTIONS=	x11
PKG_SUGGESTED_OPTIONS=	x11

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	x11

.if !empty(PKG_OPTIONS:Mx11)
PLIST.x11=	yes
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-x
.endif
