# $NetBSD: Makefile,v 1.9 2004/04/25 20:37:39 snj Exp $

DISTNAME=		evolution-1.2.4
PKGREVISION=		10
CATEGORIES=		mail time gnome
MASTER_SITES=		ftp://ftp.ximian.com/pub/ximian-evolution/source/ \
			ftp://ximian.netnitco.net/pub/mirrors/ximian/ximian-evolution/source/ \
			http://public.planetmirror.com/pub/ximian/ximian-evolution/source/ \
			ftp://mirror.pa.msu.edu/ximian/ximian-evolution/source/ \
			ftp://titan.pcis.net/mirrors/ximian/ximian-evolution/source/ \
			ftp://www.linux.org.ar/pub/ximian/ximian-evolution/source/ \
			ftp://www.mirror.ac.uk/sites/ftp.ximian.com/pub/ximian-evolution/source/ \
			ftp://ftp-stud.fht-esslingen.de/pub/Mirrors/ftp.ximian.com/ximian-evolution/source/ \
			ftp://ftp.tux.is/ximian/ximian-evolution/source/ \
			ftp://sunsite.cnlab-switch.ch/mirror/ximian/ximian-evolution/source/ \
			${MASTER_SITE_GNOME:=sources/evolution/1.2/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://ximian.com/products/evolution/
COMMENT=		GNOME mailer, calendar, contact manager, and communications tool

BUILD_DEPENDS+=		bison-[0-9]*:../../devel/bison
DEPENDS+=		psmisc-[0-9]*:../../sysutils/psmisc
BUILD_USES_MSGFMT=	YES

# Using a wildcard here doesn't make sense because the version number of
# "db3" is hardcoded in the "configure" script and some source modules.
BUILDLINK_DEPENDS.db3=		db3-3.11.2{,nb*}
BUILDLINK_DEPENDS.libxml=	libxml>=1.8.17

GNU_CONFIGURE=		YES
USE_GNU_TOOLS+=		make
USE_X11BASE=		YES
USE_LIBTOOL=		YES
USE_BUILDLINK3=		YES
USE_DIRS+=		gnome1-1.5
USE_PKGLOCALEDIR=	YES
YACC=			${PREFIX}/bin/bison -y

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
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
CONFIGURE_ARGS+=	--enable-nntp=yes
CONFIGURE_ARGS+=	--enable-openssl=yes
CONFIGURE_ARGS+=	--with-krb5=/usr --with-krb4=/usr
CONFIGURE_ARGS+=	--with-db3-includes=${LOCALBASE}/include/db3
CONFIGURE_ARGS+=	--with-db3-libs=${LOCALBASE}/lib
CONFIGURE_ENV+=		PKG_CONFIG_PATH="${LOCALBASE}/lib/pkgconfig:${X11BASE}/lib/pkgconfig"

pre-configure:
	for i in ${WRKSRC}/widgets/*/Makefile.in			\
		 ${WRKSRC}/mail/*/Makefile.in				\
		 ${WRKSRC}/shell/*/Makefile.in ; do			\
		${SED} <$$i >$$i.fixed					\
		 -e 's/^\(LTCOMPILE.*\)$$/\1 $${BONOBO_GNOME_CFLAGS}/'	\
		 -e 's/^\(COMPILE.*\)$$/\1 $${BONOBO_GNOME_CFLAGS}/' &&	\
		${MV} $$i.fixed $$i ;					\
	done

.include "../../mk/bsd.prefs.mk"

.include "../../textproc/libunicode/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../print/gnome-print/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../databases/db3/buildlink3.mk"
.include "../../databases/openldap/buildlink3.mk"
.include "../../www/gtkhtml/buildlink3.mk"
.include "../../devel/bonobo/buildlink3.mk"
.include "../../devel/bonobo-conf/buildlink3.mk"
.include "../../devel/oaf/buildlink3.mk"
.include "../../devel/gal/buildlink3.mk"
.include "../../net/ORBit/buildlink3.mk"
.include "../../net/soup/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
