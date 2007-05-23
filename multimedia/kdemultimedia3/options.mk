# $NetBSD: options.mk,v 1.2 2007/05/23 13:16:11 markd Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.kdemultimedia
PKG_SUPPORTED_OPTIONS=	gstreamer oss

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgstreamer)
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Moss)
CONFIGURE_ARGS+=	--enable-audio=oss
.endif
