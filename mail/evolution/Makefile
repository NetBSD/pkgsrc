# $NetBSD: Makefile,v 1.9 2001/10/05 22:47:33 tron Exp $

DISTNAME=		evolution-0.14
CATEGORIES=		mail time gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=unstable/sources/evolution/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.ximian.com/products/ximian_evolution/
COMMENT=		GNOME mailer, calendar, contact manager, and communications tool

BUILD_DEPENDS+=		automake>=1.4:../../devel/automake

DEPENDS+=		bison-[0-9]*:../../devel/bison
DEPENDS+=		db3-2.9:../../databases/db3
DEPENDS+=		gal>=0.12:../../devel/gal
DEPENDS+=		bonobo>=1.0.7:../../devel/bonobo
DEPENDS+=		bonobo-conf>=0.11:../../devel/bonobo-conf
DEPENDS+=		gtkhtml>=0.13.0:../../www/gtkhtml
DEPENDS+=		gnome-vfs>=1.0.1:../../sysutils/gnome-vfs
DEPENDS+=		libunicode>=0.4:../../textproc/libunicode
DEPENDS+=		oaf>=0.6.5:../../devel/oaf
DEPENDS+=		ORBit>=0.5.8:../../net/ORBit
DEPENDS+=		gnome-print>=0.29:../../print/gnome-print
DEPENDS+=		gdk-pixbuf>=0.9.0:../../graphics/gdk-pixbuf
BUILD_USES_MSGFMT=	YES

GNU_CONFIGURE=		YES
USE_GMAKE=		YES
USE_X11BASE=		YES
USE_LIBINTL=		YES
USE_LIBTOOL=		YES
YACC=			${PREFIX}/bin/bison -y

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
CONFIGURE_ARGS+=	--enable-ldap=no
CONFIGURE_ARGS+=	--with-db3-includes=${LOCALBASE}/include/db3
CONFIGURE_ARGS+=	--with-db3-libs=${LOCALBASE}/lib
CONFIGURE_ENV+=		CFLAGS="-D_POSIX_THREAD_SYSCALL_SOFT=1 ${CFLAGS}"
CPPFLAGS+=		-D_POSIX_THREAD_SYSCALL_SOFT=1

pre-configure:
	(cd ${WRKSRC} && ${LOCALBASE}/bin/automake)

.include "../../security/openssl/buildlink.mk"
.include "../../databases/db3/buildlink.mk"
.include "../../devel/bonobo/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
