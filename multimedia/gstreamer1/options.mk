# $NetBSD: options.mk,v 1.5 2016/12/01 11:08:56 martin Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gstreamer
PKG_SUPPORTED_OPTIONS=	gstreamer-gstcheck introspection
PKG_SUGGESTED_OPTIONS=	introspection

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	gstcheck introspection
.if !empty(PKG_OPTIONS:Mgstreamer-gstcheck)
.include "../../devel/check/buildlink3.mk"
PLIST.gstcheck=	yes
# don't worry if the "GstABI" check fails -- GstPlugin contains
# off_t and time_t which are system dependent
TEST_TARGET=	check-torture
.else
CONFIGURE_ARGS+=--disable-check
.endif
.if !empty(PKG_OPTIONS:Mintrospection)
.include "../../devel/gobject-introspection/buildlink3.mk"
PLIST.introspection=yes
.else
CONFIGURE_ARGS+=--disable-introspection
.endif
