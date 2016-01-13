# $NetBSD: options.mk,v 1.30 2016/01/13 22:25:38 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.libpurple
PKG_SUPPORTED_OPTIONS+=		avahi dbus debug farstream gnome gnutls
PKG_SUPPORTED_OPTIONS+=		gstreamer perl sasl tcl
PKG_SUGGESTED_OPTIONS+=		dbus farstream gnome gstreamer

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		avahi dbus gnome gnutls nss perl tcl

.if !empty(PKG_OPTIONS:Mavahi)
PLIST.avahi=		yes
CONFIGURE_ARGS+=	--enable-avahi
.  include "../../net/avahi/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mgnome)
PLIST.gnome=		yes
.  include "../../devel/GConf/schemas.mk"
GCONF_SCHEMAS+=		purple.schemas
.else
CONFIGURE_ARGS+=	--disable-schemas-install
CONFIGURE_ENV+=		ac_cv_path_GCONFTOOL="no"
.endif

.if !empty(PKG_OPTIONS:Mgnutls)
PLIST.gnutls=		yes
CONFIGURE_ARGS+=	--enable-gnutls
CONFIGURE_ARGS+= --with-gnutls-includes=${BUILDLINK_PREFIX.gnutls}/include
CONFIGURE_ARGS+= --with-gnutls-libs=${BUILDLINK_PREFIX.gnutls}/lib
.  include "../../security/gnutls/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-gnutls
PLIST.nss=		yes
CONFIGURE_ARGS+=	--enable-nss
CONFIGURE_ARGS+= --with-nspr-includes=${BUILDLINK_PREFIX.nspr}/include/nspr
CONFIGURE_ARGS+= --with-nspr-libs=${BUILDLINK_PREFIX.nspr}/lib/nspr
CONFIGURE_ARGS+= --with-nss-includes=${BUILDLINK_PREFIX.nss}/include/nss/nss
CONFIGURE_ARGS+= --with-nss-libs=${BUILDLINK_PREFIX.nss}/lib/nss
.  include "../../devel/nss/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mperl)
PLIST.perl=		yes
CONFIGURE_ARGS+=	--enable-perl
USE_TOOLS+=		perl:run
PERL5_PACKLIST_DIR=	${PREFIX}/lib/purple-2/perl
PERL5_PACKLIST=		auto/Purple/.packlist
.  include "../../lang/perl5/packlist.mk"
.  include "../../lang/perl5/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mtcl)
PLIST.tcl=		yes
CONFIGURE_ARGS+=	--enable-tcl
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

# voice/video support requires both farstream and gstreamer
.if !empty(PKG_OPTIONS:Mfarstream) && !empty(PKG_OPTIONS:Mgstreamer)
CONFIGURE_ARGS+=	--enable-vv
PLIST.vv=		yes
.endif

.if !empty(PKG_OPTIONS:Mfarstream)
CONFIGURE_ARGS+=	--enable-farstream
.  include "../../chat/farstream/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mgstreamer)
CONFIGURE_ARGS+=	--enable-gstreamer
.  include "../../multimedia/gstreamer1/buildlink3.mk"
.  include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.endif
