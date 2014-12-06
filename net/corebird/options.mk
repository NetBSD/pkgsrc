# $NetBSD: options.mk,v 1.1 2014/12/06 09:14:11 obache Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.corebird
PKG_SUPPORTED_OPTIONS=	gstreamer
PKG_SUGGESTED_OPTIONS=	gstreamer

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgstreamer)
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
DEPENDS+=	gst-plugins1-bad-[0-9]*:../../multimedia/gst-plugins1-bad
DEPENDS+=	gst-plugins1-good-[0-9]*:../../multimedia/gst-plugins1-good
DEPENDS+=	gst-libav-[0-9]*:../../multimedia/gst-plugins1-libav
CONFIGURE_ARGS+=	--enable-video
.else
CONFIGURE_ARGS+=	--disable-video
.endif
