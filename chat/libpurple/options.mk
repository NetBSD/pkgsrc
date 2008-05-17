# $NetBSD: options.mk,v 1.8 2008/05/17 23:26:06 tnn Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.libpurple
PKG_SUPPORTED_OPTIONS+=		gnutls perl tcl debug dbus sasl
PKG_SUGGESTED_OPTIONS+=		gnutls

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		dbus

.if !empty(PKG_OPTIONS:Mgnutls)
CONFIGURE_ARGS+=	--enable-gnutls
CONFIGURE_ARGS+= --with-gnutls-includes=${BUILDLINK_PREFIX.gnutls}/include
CONFIGURE_ARGS+= --with-gnutls-libs=${BUILDLINK_PREFIX.gnutls}/lib

.  include "../../security/gnutls/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--enable-nss
CONFIGURE_ARGS+= --with-nspr-includes=${BUILDLINK_PREFIX.nspr}/include/nspr
CONFIGURE_ARGS+= --with-nspr-libs=${BUILDLINK_PREFIX.nspr}/lib/nspr
CONFIGURE_ARGS+= --with-nss-includes=${BUILDLINK_PREFIX.nss}/include/nss/nss
CONFIGURE_ARGS+= --with-nss-libs=${BUILDLINK_PREFIX.nss}/lib/nss

.  include "../../devel/nss/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mperl)
CONFIGURE_ARGS+=	--enable-perl
USE_TOOLS+=		perl:run
.  include "../../lang/perl5/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mtcl)
CONFIGURE_ARGS+=	--with-tclconfig=${BUILDLINK_PREFIX.tcl}/lib
.  include "../../lang/tcl/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mdbus)
CONFIGURE_ARGS+=	--enable-dbus
CONFIGURE_ARGS+=	--with-python=${PYTHONBIN}
PLIST.dbus=		yes
REPLACE_SH+=		libpurple/purple-send
REPLACE_SH+=		libpurple/purple-send-async
REPLACE_PYTHON+=	libpurple/purple-remote
REPLACE_PYTHON+=	libpurple/purple-url-handler
.  include "../../sysutils/py-dbus/buildlink3.mk"
.  include "../../sysutils/dbus/buildlink3.mk"
.  include "../../sysutils/dbus-glib/buildlink3.mk"
.  include "../../lang/python/application.mk"
.endif

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if !empty(PKG_OPTIONS:Msasl)
CONFIGURE_ARGS+=	--enable-cyrus-sasl
.  include "../../security/cyrus-sasl/buildlink3.mk"
.endif
