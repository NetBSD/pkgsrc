# $NetBSD: options.mk,v 1.1 2005/12/09 20:40:56 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.groff
PKG_SUPPORTED_OPTIONS=	x11
PKG_SUGGESTED_OPTIONS=	x11

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mx11)
CONFIGURE_ARGS+=	--with-x
CONFIGURE_ARGS+=	--with-appresdir=${PREFIX}/lib/X11/app-defaults
PLIST_SRC=		PLIST.x11 PLIST
.include "../../mk/xaw.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-x
.endif
