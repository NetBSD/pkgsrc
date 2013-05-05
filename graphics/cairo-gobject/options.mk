# $NetBSD: options.mk,v 1.1 2013/05/05 13:44:23 spz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.cairo-gobject
PKG_SUPPORTED_OPTIONS=	x11
PKG_SUGGESTED_OPTIONS=	x11

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		x11

###
### decide between Quartz, GL or nothing
###
.if exists(/System/Library/Frameworks/Carbon.framework)
CONFIGURE_ARGS+=        --enable-quartz
CONFIGURE_ARGS+=        --enable-quartz-font
CONFIGURE_ARGS+=        --enable-quartz-image
CONFIGURE_ARGS+=        --disable-gl
CONFIGURE_ARGS+=        --disable-xlib
CONFIGURE_ARGS+=        --disable-xlib-xrender
.else
.if !empty(PKG_OPTIONS:Mx11)
CONFIGURE_ARGS+=	--enable-gl
.endif
.endif

