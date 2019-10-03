# $NetBSD: options.mk,v 1.9 2019/10/03 20:45:19 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gstreamer
PKG_SUPPORTED_OPTIONS=	gstreamer-gstcheck introspection gstreamer-ptp-suid
PKG_SUGGESTED_OPTIONS=	gstreamer-gstcheck introspection

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	gstcheck introspection

.if !empty(PKG_OPTIONS:Mgstreamer-gstcheck)
.include "../../devel/check/buildlink3.mk"
PLIST.gstcheck=		yes
# don't worry if the "GstABI" check fails -- GstPlugin contains
# off_t and time_t which are system dependent
TEST_TARGET=		check-torture
.else
CONFIGURE_ARGS+=	--disable-check
.endif

.if !empty(PKG_OPTIONS:Mintrospection)
.include "../../devel/gobject-introspection/buildlink3.mk"
PLIST.introspection=	yes
.else
CONFIGURE_ARGS+=	--disable-introspection
.endif

.if !empty(PKG_OPTIONS:Mgstreamer-ptp-suid)
SPECIAL_PERMS+=		libexec/gstreamer-1.0/gst-ptp-helper ${SETUID_ROOT_PERMS}
CONFIGURE_ARGS+=	--with-ptp-helper-permissions=setuid-root
.else
CONFIGURE_ARGS+=	--with-ptp-helper-permissions=none
.endif
