# $NetBSD: Makefile,v 1.205 2014/01/01 11:52:07 wiz Exp $

DISTNAME=		evolution-2.32.3
PKGREVISION=		28
CATEGORIES=		mail time gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/evolution/2.32/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnome.org/projects/evolution/
COMMENT=		GNOME mailer, calendar, contact manager, and communications tool
#LICENSE=		modified-bsd AND gnu-lgpl-v2.1 AND gnu-lgpl-v3 AND perhaps more

.include "options.mk"

GNU_CONFIGURE=		YES
USE_TOOLS+=		bison gmake intltool msgfmt pkg-config
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES

REPLACE_PERL+=		addressbook/tools/csv2vcard
REPLACE_PERL+=		addressbook/tools/evolution-addressbook-clean
REPLACE_PERL+=		addressbook/tools/evolution-addressbook-clean.in

CONFIGURE_ARGS+=	--with-openldap
CONFIGURE_ARGS+=	--without-static-ldap
CONFIGURE_ARGS+=	--enable-pilot-conduits=no
.if defined(PKGREVISION)
CONFIGURE_ARGS+=	--with-sub-version=nb${PKGREVISION}
.endif
CONFIGURE_ARGS+=	--disable-nm
CONFIGURE_ARGS+=	--disable-audio-inline
CONFIGURE_ARGS+=	--disable-image-inline
CONFIGURE_ARGS+=	--disable-pst-import

PKGCONFIG_OVERRIDE=	evolution-calendar.pc.in
PKGCONFIG_OVERRIDE+=	evolution-mail.pc.in
PKGCONFIG_OVERRIDE+=	evolution-plugin.pc.in
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

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" && !empty(OS_VERSION:M4.*)
BUILDLINK_TRANSFORM+=	rm:-Wl,--no-undefined
.endif

LDFLAGS.SunOS+=		-lldap

.if !exists(/usr/include/semaphore.h)
LDFLAGS+=	-lsemaphore
.include "../../devel/pthread-sem/buildlink3.mk"
.endif
.include "../../databases/openldap-client/buildlink3.mk"
.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../devel/atk/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.16.0
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.gnome-icon-theme+=	gnome-icon-theme>=2.30.2.1
.include "../../devel/libgweather/buildlink3.mk"
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
BUILDLINK_API_DEPENDS.evolution-data-server+=	evolution-data-server>=2.24.3
.include "../../mail/evolution-data-server/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../net/libsoup24/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../www/gtkhtml314/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.12.0
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gnome-desktop/buildlink3.mk"
.include "../../x11/libunique/buildlink3.mk"
.include "../../audio/libcanberra/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
