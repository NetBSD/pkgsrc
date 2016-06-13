# $NetBSD: options.mk,v 1.2 2016/06/13 23:06:46 youri Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.polkit
PKG_SUPPORTED_OPTIONS=	introspection pam
PKG_SUGGESTED_OPTIONS=	pam

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	introspection pam

.if !empty(PKG_OPTIONS:Mintrospection)
BUILDLINK_DEPMETHOD.gobject-introspection+=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-introspection
PLIST.introspection=	yes
.else
CONFIGURE_ARGS+=	--disable-introspection
.endif

.if !empty(PKG_OPTIONS:Mpam)
.include "../../mk/pam.buildlink3.mk"
CONFIGURE_ARGS+=	--with-authfw=pam
CONFIGURE_ARGS+=	--with-pam-module-dir=${PREFIX}/lib/security
PLIST.pam=	yes
.include "../../mk/bsd.prefs.mk"
.  if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	--with-pam-include=system
.  endif
MAKE_DIRS+=	/etc/pam.d
CONF_FILES+=	${PREFIX}/share/examples/pam.d/polkit-1 \
		/etc/pam.d/polkit-1
.else
CONFIGURE_ARGS+=	--with-authfw=shadow
CONFIGURE_ARGS+=	--disable-pam-module
.endif
