# $NetBSD: options.mk,v 1.1.1.1 2009/08/17 21:10:28 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libnice
PKG_SUPPORTED_OPTIONS=	gstreamer
PKG_SUGGESTED_OPTIONS=	gstreamer

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	gstreamer

.if !empty(PKG_OPTIONS:Mgstreamer)
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
PLIST.gstreamer=	yes
.else
CONFIGURE_ARGS+=	--without-gstreamer
.endif
