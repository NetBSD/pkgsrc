# $NetBSD: options.mk,v 1.2 2013/04/08 11:17:17 rodent Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gstreamer
PKG_SUPPORTED_OPTIONS=	gstcheck

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	gstcheck
.if !empty(PKG_OPTIONS:Mgstcheck)
.include "../../devel/check/buildlink3.mk"
PLIST.gstcheck=	yes
# don't worry if the "GstABI" check fails -- GstPlugin contains
# off_t and time_t which are system dependent
TEST_TARGET=	check-torture
.else
CONFIGURE_ARGS+=--disable-check
.endif
