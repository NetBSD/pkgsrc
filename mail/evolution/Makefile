# $NetBSD: Makefile,v 1.19 2002/07/12 23:39:49 mycroft Exp $

DISTNAME=		evolution-1.0.8
CATEGORIES=		mail time gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/evolution/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.ximian.com/products/ximian_evolution/
COMMENT=		GNOME mailer, calendar, contact manager, and communications tool

BUILD_DEPENDS+=		bison-[0-9]*:../../devel/bison
DEPENDS+=		bonobo-conf>=0.14nb1:../../devel/bonobo-conf
DEPENDS+=		psmisc-[0-9]*:../../sysutils/psmisc
BUILD_USES_MSGFMT=	YES

BUILDLINK_DEPENDS.gdk-pixbuf=		gdk-pixbuf>=0.11.0nb1
BUILDLINK_DEPENDS.gdk-pixbuf-gnome=	gdk-pixbuf-gnome>=0.11.0nb1
# Using a wildcard here doesn't make sence because the version number of
# "db3" is hardcoded in the "configure" script.
BUILDLINK_DEPENDS.db3=			db3-3.11.2

GNU_CONFIGURE=		YES
USE_GMAKE=		YES
USE_X11BASE=		YES
USE_LIBTOOL=		YES
YACC=			${PREFIX}/bin/bison -y

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
REPLACE_PERL+=		libical/scripts/mkderivedvalues.pl
REPLACE_PERL+=		libical/scripts/mkparameterrestrictions.pl
REPLACE_PERL+=		libical/scripts/mkrestrictionrecords.pl
REPLACE_PERL+=		libical/scripts/mkrestrictiontable.pl
REPLACE_PERL+=		tools/csv2vcard
REPLACE_PERL+=		tools/evolution-addressbook-clean.in
REPLACE_PERL+=		tools/killev
CONFIGURE_ARGS+=	--with-openldap --without-static-ldap
CONFIGURE_ARGS+=	--enable-nntp=yes
CONFIGURE_ARGS+=	--with-db3-includes=${LOCALBASE}/include/db3
CONFIGURE_ARGS+=	--with-db3-libs=${LOCALBASE}/lib
CONFIGURE_ENV+=		CFLAGS="-D_POSIX_THREAD_SYSCALL_SOFT=1 ${CFLAGS}"
CPPFLAGS+=		-D_POSIX_THREAD_SYSCALL_SOFT=1

pre-configure:
	for i in ${WRKSRC}/widgets/*/Makefile.in			\
		 ${WRKSRC}/mail/*/Makefile.in				\
		 ${WRKSRC}/shell/*/Makefile.in ; do			\
		${SED} <$$i >$$i.fixed					\
		 -e 's/^\(LTCOMPILE.*\)$$/\1 $${BONOBO_GNOME_CFLAGS}/'	\
		 -e 's/^\(COMPILE.*\)$$/\1 $${BONOBO_GNOME_CFLAGS}/' &&	\
		${MV} $$i.fixed $$i ;					\
	done

.include "../../textproc/libunicode/buildlink.mk"
.include "../../sysutils/gnome-vfs/buildlink.mk"
.include "../../devel/gettext-lib/buildlink.mk"
.include "../../print/gnome-print/buildlink.mk"
.include "../../security/openssl/buildlink.mk"
.include "../../databases/db3/buildlink.mk"
.include "../../databases/openldap/buildlink.mk"
.include "../../www/gtkhtml/buildlink.mk"
.include "../../devel/bonobo/buildlink.mk"
.include "../../devel/oaf/buildlink.mk"
.include "../../devel/gal/buildlink.mk"
.include "../../net/ORBit/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
