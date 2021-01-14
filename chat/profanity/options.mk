# $NetBSD: options.mk,v 1.1 2021/01/14 12:50:25 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.profanity
PKG_SUPPORTED_OPTIONS=	libnotify gtk2 xscrnsaver
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

# gtk2
.if !empty(PKG_OPTIONS:Mgtk2)
.include "../../x11/gtk2/buildlink3.mk"
.endif

# libnotify
.if !empty(PKG_OPTIONS:Mlibnotify)
.include "../../sysutils/libnotify/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-notifications
.endif

# xscrnsaver
.if !empty(PKG_OPTIONS:Mxscrnsaver)
.include "../../x11/libXScrnSaver/buildlink3.mk"
.endif
