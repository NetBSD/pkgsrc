# $NetBSD: Makefile,v 1.47 2004/01/14 07:27:51 xtraeme Exp $

DISTNAME=		evolution-1.4.5
PKGREVISION=		1
CATEGORIES=		mail time gnome
MASTER_SITES=		ftp://ftp.ximian.com/pub/source/evolution/ \
			${MASTER_SITE_GNOME:=sources/evolution/1.4/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://ximian.com/products/evolution/
COMMENT=		GNOME mailer, calendar, contact manager, and communications tool

BUILD_DEPENDS+=		bison-[0-9]*:../../devel/bison
DEPENDS+=		gnome2-dirs>=1.2:../../misc/gnome2-dirs
DEPENDS+=		psmisc-[0-9]*:../../sysutils/psmisc
BUILD_USES_MSGFMT=	YES

# Using a wildcard here doesn't make sense because the version number of
# "db3" is hardcoded in the "configure" script and some source modules
# to make sure locally stored mails remain in the same format!
BUILDLINK_DEPENDS.db3=		db3-3.11.2{,nb*}

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		USE_INET6

.if defined(USE_INET6) && !empty(USE_INET6:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--enable-ipv6=yes
.else
CONFIGURE_ARGS+=	--enable-ipv6=no
.endif

GNU_CONFIGURE=		YES
USE_GMAKE=		YES
USE_X11=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool ${WRKSRC}/libical/libtool
USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
YACC=			${PREFIX}/bin/bison -y

REPLACE_PERL+=		libical/scripts/mkderivedvalues.pl
REPLACE_PERL+=		libical/scripts/mkparameterrestrictions.pl
REPLACE_PERL+=		libical/scripts/mkrestrictionrecords.pl
REPLACE_PERL+=		libical/scripts/mkrestrictiontable.pl
REPLACE_PERL+=		tools/csv2vcard
REPLACE_PERL+=		tools/evolution-addressbook-clean.in
REPLACE_PERL+=		tools/killev
CPPFLAGS+=		-I/usr/include/krb5 -I/usr/include/gssapi
CONFIGURE_ARGS+=	--disable-gtk-doc
CONFIGURE_ARGS+=	--with-openldap --without-static-ldap
CONFIGURE_ARGS+=	--enable-openssl=yes
CONFIGURE_ARGS+=	--with-krb5=/usr --with-krb4=/usr
CONFIGURE_ARGS+=	--with-db3-includes=${LOCALBASE}/include/db3
CONFIGURE_ARGS+=	--with-db3-libs=${LOCALBASE}/lib
CONFIGURE_ENV+=		PKG_CONFIG_PATH="${LOCALBASE}/lib/pkgconfig:${X11BASE}/lib/pkgconfig"

PKGCONFIG_OVERRIDE=	camel.pc.in
PKGCONFIG_OVERRIDE+=	evolution-shell.pc.in
PKGCONFIG_OVERRIDE+=	evolution-calendar.pc.in
PKGCONFIG_OVERRIDE+=	evolution-addressbook.pc.in

GCONF2_SCHEMAS=		apps_evolution_shell.schemas
GCONF2_SCHEMAS+=	apps_evolution_addressbook.schemas
GCONF2_SCHEMAS+=	apps_evolution_calendar.schemas
GCONF2_SCHEMAS+=	apps_evolution_summary.schemas
GCONF2_SCHEMAS+=	evolution-mail.schemas

pre-configure:
	for i in ${WRKSRC}/camel/providers/*/Makefile.in ; do		\
		${SED} <$$i >$$i.fixed					\
		 -e 's|^\(lib.*_la_LIBADD.*\)$$|\1 ../../libcamel.la|' &&\
		${MV} $$i.fixed $$i ;					\
	done

.include "../../databases/db3/buildlink2.mk"
.include "../../databases/openldap/buildlink2.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/gal2/buildlink2.mk"
.include "../../devel/libbonoboui/buildlink2.mk"
.include "../../devel/libglade2/buildlink2.mk"
.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../graphics/libgnomecanvas/buildlink2.mk"
.include "../../print/libgnomeprint/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../sysutils/gnome-vfs2/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../textproc/libunicode/buildlink2.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../www/gtkhtml3/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
