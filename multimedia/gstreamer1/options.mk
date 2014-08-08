# $NetBSD: options.mk,v 1.3 2014/08/08 21:24:51 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gstreamer
PKG_SUPPORTED_OPTIONS=	gstreamer-gstcheck

PKG_OPTIONS_LEGACY_OPTS+=	gstcheck:gstreamer-gstcheck

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	gstcheck
.if !empty(PKG_OPTIONS:Mgstreamer-gstcheck)
.include "../../devel/check/buildlink3.mk"
PLIST.gstcheck=	yes
# don't worry if the "GstABI" check fails -- GstPlugin contains
# off_t and time_t which are system dependent
TEST_TARGET=	check-torture
.else
CONFIGURE_ARGS+=--disable-check
.endif
