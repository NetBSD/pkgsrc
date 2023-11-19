# $NetBSD: options.mk,v 1.1 2023/11/19 13:00:26 bacon Exp $
### Set options
PKG_OPTIONS_VAR=	PKG_OPTIONS.qemacs
PKG_SUPPORTED_OPTIONS=	x11
PKG_SUGGESTED_OPTIONS=	x11

PLIST_VARS+=	html

.include "../../mk/bsd.options.mk"

# maybe consider ffmpeg, xv and xshm support later

###
### Support x11
###
.if !empty(PKG_OPTIONS:Mx11)
CONFIGURE_ARGS+=	--enable-x11
CONFIGURE_ARGS+=	--enable-html
CONFIGURE_ARGS+=	--enable-png
PLIST.html=            yes
.include "../../x11/libX11/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-x11
.endif
