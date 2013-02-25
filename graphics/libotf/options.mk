# $NetBSD: options.mk,v 1.2 2013/02/25 16:13:28 jperkin Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libotf
PKG_SUPPORTED_OPTIONS=	x11
PKG_SUGGESTED_OPTIONS=	x11

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		x11

.if !empty(PKG_OPTIONS:Mx11)
.include "../../mk/xaw.buildlink3.mk"
PLIST.x11=		yes
.else
CONFIGURE_ARGS+=	--without-x
.endif
