# $NetBSD: Makefile,v 1.65 2004/10/03 00:12:52 tv Exp $

DISTNAME=		evolution-2.0.0
PKGREVISION=		1
CATEGORIES=		mail time gnome
MASTER_SITES=		ftp://ftp.ximian.com/pub/source/evolution/ \
			${MASTER_SITE_GNOME:=sources/evolution/2.0/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://ximian.com/products/evolution/
COMMENT=		GNOME mailer, calendar, contact manager, and communications tool

DEPENDS+=		psmisc-[0-9]*:../../sysutils/psmisc
BUILD_USES_MSGFMT=	YES

BUILDLINK_DEPENDS.glib2+=	glib2>=2.4.0nb2

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		USE_INET6

.if defined(USE_INET6) && !empty(USE_INET6:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--enable-ipv6=yes
.else
CONFIGURE_ARGS+=	--enable-ipv6=no
.endif

GNU_CONFIGURE=		YES
USE_DIRS+=		gnome2-1.5
USE_GNU_TOOLS+=		make yacc
USE_X11=		YES
USE_LIBTOOL=		YES
USE_BUILDLINK3=		YES
USE_PKGLOCALEDIR=	YES

REPLACE_PERL+=		addressbook/tools/csv2vcard
REPLACE_PERL+=		addressbook/tools/evolution-addressbook-clean
REPLACE_PERL+=		addressbook/tools/evolution-addressbook-clean.in

CPPFLAGS+=		-I/usr/include/gssapi
CPPFLAGS+=		-I/usr/include/krb5

CONFIGURE_ARGS+=	--disable-gtk-doc
CONFIGURE_ARGS+=	--with-openldap
CONFIGURE_ARGS+=	--without-static-ldap
CONFIGURE_ARGS+=	--enable-nss=no
CONFIGURE_ARGS+=	--enable-openssl=yes
CONFIGURE_ARGS+=	--enable-pilot-conduits=no
CONFIGURE_ARGS+=	--enable-smime=no
CONFIGURE_ARGS+=	--with-krb4=/usr
CONFIGURE_ARGS+=	--with-krb5=/usr
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc
.if defined(PKGREVISION)
CONFIGURE_ARGS+=	--with-sub-version=nb${PKGREVISION}
.endif

PKGCONFIG_OVERRIDE=	camel.pc.in
PKGCONFIG_OVERRIDE+=	evolution-shell.pc.in

GCONF2_SCHEMAS=		apps_evolution_addressbook-2.0.schemas
GCONF2_SCHEMAS+=	apps_evolution_calendar-2.0.schemas
GCONF2_SCHEMAS+=	apps_evolution_shell-2.0.schemas
GCONF2_SCHEMAS+=	evolution-mail-2.0.schemas

BUILDLINK_TRANSFORM+=	rm:-DG_DISABLE_DEPRECATED
BUILDLINK_TRANSFORM+=	rm:-DGTK_DISABLE_DEPRECATED

.if !exists(/usr/include/semaphore.h)
LDFLAGS+=	-lsemaphore
.include "../../devel/pthread-sem/buildlink3.mk"
.endif
.include "../../databases/openldap/buildlink3.mk"
.include "../../devel/atk/buildlink3.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gal2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libbonoboui/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../mail/evolution-data-server/buildlink3.mk"
.include "../../net/libsoup-devel/buildlink3.mk"
.include "../../print/libgnomeprint/buildlink3.mk"
.include "../../print/libgnomeprintui/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../www/gtkhtml3/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
