# $NetBSD: options.mk,v 1.1 2022/11/28 13:04:40 nros Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.qt6-qtmultimedia
PKG_SUPPORTED_OPTIONS=		gstreamer

.include "../../mk/bsd.fast.prefs.mk"

PLIST_VARS+=			gstreamer

.if ${OPSYS} != "Darwin"
PKG_SUGGESTED_OPTIONS+=		gstreamer
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgstreamer)
CONFIGURE_ARGS+=	-gstreamer
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../multimedia/gst-plugins1-bad/buildlink3.mk"
PLIST.gstreamer=	yes
.else
CONFIGURE_ARGS+=	-no-gstreamer
.endif
