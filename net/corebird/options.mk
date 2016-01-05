# $NetBSD: options.mk,v 1.2 2016/01/05 21:38:07 joerg Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.corebird
PKG_SUPPORTED_OPTIONS=	gstreamer
PKG_SUGGESTED_OPTIONS=	gstreamer

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgstreamer)
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
DEPENDS+=	gst-plugins1-bad-[0-9]*:../../multimedia/gst-plugins1-bad
DEPENDS+=	gst-plugins1-good-[0-9]*:../../multimedia/gst-plugins1-good
DEPENDS+=	gst-plugins1-libav-[0-9]*:../../multimedia/gst-plugins1-libav
CONFIGURE_ARGS+=	--enable-video
.else
CONFIGURE_ARGS+=	--disable-video
.endif
