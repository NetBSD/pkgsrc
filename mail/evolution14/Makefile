# $NetBSD: Makefile,v 1.18 2006/01/24 07:32:19 wiz Exp $

DISTNAME=		evolution-1.4.6
PKGNAME=		${DISTNAME:S/evolution/evolution14/}
PKGREVISION=		7
CATEGORIES=		mail time gnome
MASTER_SITES=		ftp://ftp.ximian.com/pub/source/evolution/ \
			${MASTER_SITE_GNOME:=sources/evolution/1.4/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://ximian.com/products/evolution/
COMMENT=		GNOME mailer, calendar, contact manager, and communications tool

CONFLICTS+=		evolution12-[0-9]*

DEPENDS+=		psmisc-[0-9]*:../../sysutils/psmisc
BUILD_USES_MSGFMT=	YES

BUILDLINK_DEPENDS.glib2+=	glib2>=2.4.0nb2

# Using a wildcard here doesn't make sense because the version number of
# "db3" is hardcoded in the "configure" script and some source modules
# to make sure locally stored mails remain in the same format!
BUILDLINK_DEPENDS.db3=		db3-3.11.2{,nb*}

.include "options.mk"

GNU_CONFIGURE=		YES
USE_DIRS+=		gnome2-1.5
USE_TOOLS+=		bison gmake pkg-config
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES

REPLACE_PERL+=		libical/scripts/mkderivedvalues.pl
REPLACE_PERL+=		libical/scripts/mkparameterrestrictions.pl
REPLACE_PERL+=		libical/scripts/mkderivedcomponents.pl
REPLACE_PERL+=		libical/scripts/mkderivedparameters.pl
REPLACE_PERL+=		libical/scripts/mkderivedproperties.pl
REPLACE_PERL+=		libical/scripts/mkrestrictionrecords.pl
REPLACE_PERL+=		libical/scripts/mkrestrictiontable.pl
REPLACE_PERL+=		tools/csv2vcard
REPLACE_PERL+=		tools/evolution-addressbook-clean
REPLACE_PERL+=		tools/evolution-addressbook-clean.in
REPLACE_PERL+=		tools/killev
CPPFLAGS+=		-I/usr/include/krb5 -I/usr/include/gssapi
CONFIGURE_ARGS+=	--disable-gtk-doc
CONFIGURE_ARGS+=	--with-openldap --without-static-ldap
CONFIGURE_ARGS+=	--enable-openssl=yes
CONFIGURE_ARGS+=	--with-krb5=/usr --with-krb4=/usr
CONFIGURE_ARGS+=	--with-db3-includes=${LOCALBASE}/include/db3
CONFIGURE_ARGS+=	--with-db3-libs=${LOCALBASE}/lib

PKGCONFIG_OVERRIDE=	camel.pc.in
PKGCONFIG_OVERRIDE+=	evolution-shell.pc.in
PKGCONFIG_OVERRIDE+=	evolution-calendar.pc.in
PKGCONFIG_OVERRIDE+=	evolution-addressbook.pc.in

GCONF2_SCHEMAS=		apps_evolution_shell.schemas
GCONF2_SCHEMAS+=	apps_evolution_addressbook.schemas
GCONF2_SCHEMAS+=	apps_evolution_calendar.schemas
GCONF2_SCHEMAS+=	apps_evolution_summary.schemas
GCONF2_SCHEMAS+=	evolution-mail.schemas

BUILDLINK_TRANSFORM+=	rm:-DG_DISABLE_DEPRECATED
BUILDLINK_TRANSFORM+=	rm:-DGTK_DISABLE_DEPRECATED

.if !exists(/usr/include/semaphore.h)
LDFLAGS+=	-lsemaphore
.include "../../devel/pthread-sem/buildlink3.mk"
.endif
.include "../../databases/db3/buildlink3.mk"
.include "../../databases/openldap/buildlink3.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gal20/buildlink3.mk"
.include "../../devel/libbonoboui/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../print/libgnomeprint/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/gnome-spell/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libunicode/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../www/gtkhtml30/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
