# $NetBSD: options.mk,v 1.1 2012/12/02 01:21:51 cheusov Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.lirc
PKG_SUPPORTED_OPTIONS=	x11
PKG_SUGGESTED_OPTIONS=	x11

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		x11

.if !empty(PKG_OPTIONS:Mx11)
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
PLIST.x11=		yes
.else
CONFIGURE_ARGS+=	--without-x
.endif
