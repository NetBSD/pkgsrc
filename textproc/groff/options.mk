# $NetBSD: options.mk,v 1.16 2026/07/19 08:05:45 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.groff
PKG_SUPPORTED_OPTIONS=	ghostscript x11
PKG_SUGGESTED_OPTIONS=	ghostscript x11

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mghostscript)
USE_TOOLS+=		gs:run
PLIST_SRC+=		PLIST.docs
.else
CONFIGURE_ARGS+=	--without-gs
.endif

.if !empty(PKG_OPTIONS:Mx11)
CONFIGURE_ARGS+=	--with-x
CONFIGURE_ARGS+=	--with-appresdir=${PREFIX}/lib/X11/app-defaults
PLIST_SRC+=		PLIST.x11
.include "../../mk/xaw.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-x
.endif
