# $NetBSD: options.mk,v 1.1 2007/01/26 02:58:41 markd Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.kdemultimedia
PKG_SUPPORTED_OPTIONS=	gstreamer oss

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgstreamer)
.include "../../multimedia/gstreamer0.8/buildlink3.mk"
.include "../../multimedia/gst-plugins0.8/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Moss)
CONFIGURE_ARGS+=	--enable-audio=oss
.endif
