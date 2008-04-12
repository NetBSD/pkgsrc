# $NetBSD: options.mk,v 1.4 2008/04/12 22:43:08 jlam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.arla
PKG_SUPPORTED_OPTIONS=	x11
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		x11

.if !empty(PKG_OPTIONS:Mx11)
CONFIGURE_ARGS+=	--with-x
PLIST.x11=		yes
.include "../../x11/libXaw/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-x
.endif
