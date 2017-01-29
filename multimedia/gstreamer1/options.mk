# $NetBSD: options.mk,v 1.6 2017/01/29 23:24:10 maya Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gstreamer
PKG_SUPPORTED_OPTIONS=	gstreamer-gstcheck introspection ptp-suid
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

# PTP network clock requires setuid root for gst-ptp-helper
# It's not useful enough to be a default, but left as an option
# for those interested in it.
.if !empty(PKG_OPTIONS:Mptp-suid)
SPECIAL_PERMS+=		libexec/gstreamer-1.0/gst-ptp-helper ${SETUID_ROOT_PERMS}
CONFIGURE_ARGS+=	--with-ptp-helper-permissions=setuid-root
.else
CONFIGURE_ARGS+=	--with-ptp-helper-permissions=none
.endif
