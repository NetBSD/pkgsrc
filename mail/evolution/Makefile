# $NetBSD: Makefile,v 1.12 2001/12/03 06:27:10 tron Exp $

DISTNAME=		evolution-0.15
CATEGORIES=		mail time gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=unstable/sources/evolution/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.ximian.com/products/ximian_evolution/
COMMENT=		GNOME mailer, calendar, contact manager, and communications tool

BUILD_DEPENDS+=		bison-[0-9]*:../../devel/bison
DEPENDS+=		bonobo-conf>=0.11:../../devel/bonobo-conf
BUILD_USES_MSGFMT=	YES

BUILDLINK_DEPENDS.gdk-pixbuf=		gdk-pixbuf>=0.9.0
BUILDLINK_DEPENDS.gdk-pixbuf-gnome=	gdk-pixbuf-gnome>=0.9.0
# Using a wildcard here doesn't make sence because the version number of
# "db3" is hardcoded in the "configure" script.
BUILDLINK_DEPENDS.db3=			db3-2.11

GNU_CONFIGURE=		YES
USE_GMAKE=		YES
USE_X11BASE=		YES
USE_LIBTOOL=		YES
YACC=			${PREFIX}/bin/bison -y

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
CONFIGURE_ARGS+=	--enable-ldap=no
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
.include "../../www/gtkhtml/buildlink.mk"
.include "../../devel/bonobo/buildlink.mk"
.include "../../devel/oaf/buildlink.mk"
.include "../../devel/gal/buildlink.mk"
.include "../../net/ORBit/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
