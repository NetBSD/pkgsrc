# $NetBSD: Makefile,v 1.126 2008/01/11 13:46:38 drochner Exp $

DISTNAME=		evolution-2.12.3
CATEGORIES=		mail time gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/evolution/2.12/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.gnome.org/projects/evolution/
COMMENT=		GNOME mailer, calendar, contact manager, and communications tool

PKG_OPTIONS_VAR=	PKG_OPTIONS.evolution
PKG_SUGGESTED_OPTIONS=	inet6 ssl
PKG_SUPPORTED_OPTIONS=	inet6 krb4 krb5 ssl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mssl) && !empty(PKG_OPTIONS:Mkrb[45])
# If Kerberos is enabled, the libcrypto library is linked in, which causes
# function name conflicts with libsoftokn3 provided by Mozilla NSS.  These
# cause runtime crashes, so don't allow these options to be specified
# together.
PKG_FAIL_REASON+=	"Kerberos support conflicts with SSL"
.endif

GNU_CONFIGURE=		YES
USE_DIRS+=		gnome2-1.5
USE_TOOLS+=		bison gmake intltool msgfmt pkg-config
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES

REPLACE_PERL+=		addressbook/tools/csv2vcard
REPLACE_PERL+=		addressbook/tools/evolution-addressbook-clean
REPLACE_PERL+=		addressbook/tools/evolution-addressbook-clean.in

CPPFLAGS+=		-I/usr/include/gssapi
CPPFLAGS+=		-I/usr/include/krb5

CONFIGURE_ARGS+=	--disable-gtk-doc
CONFIGURE_ARGS+=	--with-openldap
CONFIGURE_ARGS+=	--without-static-ldap
CONFIGURE_ARGS+=	--enable-openssl=no
CONFIGURE_ARGS+=	--enable-pilot-conduits=no
CONFIGURE_ARGS+=	--with-krb4=/usr
CONFIGURE_ARGS+=	--with-krb5=/usr
.if defined(PKGREVISION)
CONFIGURE_ARGS+=	--with-sub-version=nb${PKGREVISION}
.endif

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6=yes
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if !empty(PKG_OPTIONS:Mkrb4)
CONFIGURE_ARGS+=	--with-krb4
.else
CONFIGURE_ARGS+=	--without-krb4
.endif

.if !empty(PKG_OPTIONS:Mkrb5)
CONFIGURE_ARGS+=	--with-krb5
.  include "../../mk/krb5.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-krb5
.endif

.if !empty(PKG_OPTIONS:Mssl)
CONFIGURE_ARGS+=	--enable-nss=yes
PLIST_SUBST+=		HAVE_SMIME=
PRINT_PLIST_AWK+=	/smime/ { print "$${HAVE_SMIME}" $$0; next; }
# XXX Workaround for the following problem: addressbook/util/libeabutil.la
# is compiled as a static library only which uses the NSS stuff.  When other
# parts of the program use this .la archive, they get the right -L flags
# (from the dependency_libs variable) but not the rpaths.  buildlink3 should
# add rpath flags to the dependency_libs, but there is an strange comment
# in the wrapper saying that it shouldn't.
LDFLAGS+=		${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.nss}/lib/nss
BUILDLINK_API_DEPENDS.nss+=		nss>=3.9.2nb3
.  include "../../devel/nspr/buildlink3.mk"
.  include "../../devel/nss/buildlink3.mk"

CPPFLAGS+=		-I${BUILDLINK_PREFIX.nss}/include/nss/nss

post-wrapper:
	cd ${BUILDLINK_DIR}/lib/pkgconfig && ${LN} -s nspr.pc mozilla-nspr.pc
	cd ${BUILDLINK_DIR}/lib/pkgconfig && ${LN} -s nss.pc mozilla-nss.pc
.else
CONFIGURE_ARGS+=	--disable-nss
PLIST_SUBST+=		HAVE_SMIME="@comment "
.endif

PKGCONFIG_OVERRIDE=	evolution-plugin.pc.in
PKGCONFIG_OVERRIDE+=	evolution-shell.pc.in

GCONF_SCHEMAS+= apps-evolution-attachment-reminder.schemas
GCONF_SCHEMAS+= apps-evolution-mail-notification.schemas
GCONF_SCHEMAS+= apps-evolution-mail-prompts-checkdefault.schemas
GCONF_SCHEMAS+=	apps_evolution_addressbook.schemas
GCONF_SCHEMAS+=	apps_evolution_calendar.schemas
GCONF_SCHEMAS+=	apps_evolution_shell.schemas
GCONF_SCHEMAS+= bogo-junk-plugin.schemas
GCONF_SCHEMAS+=	evolution-mail.schemas

BUILDLINK_TRANSFORM+=	rm:-DG_DISABLE_DEPRECATED
BUILDLINK_TRANSFORM+=	rm:-DGTK_DISABLE_DEPRECATED

BUILDLINK_API_DEPENDS.evolution-data-server+=	evolution-data-server>=1.4.1
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.4.0nb2
BUILDLINK_API_DEPENDS.libsoup-devel+=		libsoup-devel>=2.2.3

.if !exists(/usr/include/semaphore.h)
LDFLAGS+=	-lsemaphore
.include "../../devel/pthread-sem/buildlink3.mk"
.endif
.include "../../databases/openldap-client/buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../devel/atk/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libbonoboui/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../mail/evolution-data-server/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../net/libsoup-devel/buildlink3.mk"
.include "../../print/libgnomeprint/buildlink3.mk"
.include "../../print/libgnomeprintui/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../www/gtkhtml314/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
