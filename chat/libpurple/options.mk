# $NetBSD: options.mk,v 1.31 2020/06/12 11:40:19 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.libpurple
PKG_OPTIONS_REQUIRED_GROUPS=	ssl
PKG_OPTIONS_GROUP.ssl=		gnutls nss
PKG_SUPPORTED_OPTIONS+=		avahi dbus debug farstream
PKG_SUPPORTED_OPTIONS+=		gstreamer perl sasl tcl
PKG_SUGGESTED_OPTIONS+=		dbus farstream gstreamer gnutls

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		avahi dbus gnutls nss perl tcl vv

.if !empty(PKG_OPTIONS:Mavahi)
PLIST.avahi=		yes
CONFIGURE_ARGS+=	--enable-avahi
.  include "../../net/avahi/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mgnutls)
PLIST.gnutls=		yes
CONFIGURE_ARGS+=	--enable-gnutls
CONFIGURE_ARGS+= --with-gnutls-includes=${BUILDLINK_PREFIX.gnutls}/include
CONFIGURE_ARGS+= --with-gnutls-libs=${BUILDLINK_PREFIX.gnutls}/lib
.  include "../../security/gnutls/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mnss)
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
