# $NetBSD: Makefile,v 1.3 2001/05/25 06:16:17 rh Exp $
#

DISTNAME=		evolution-0.10
CATEGORIES=		mail time gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=unstable/sources/evolution/}

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.ximian.com/apps/evolution.php3
COMMENT=		GNOME mailer, calendar, contact manager, and communications tool

DEPENDS+=		bison-*:../../devel/bison
DEPENDS+=		gal-0.7:../../devel/gal
DEPENDS+=		bonobo>=0.36:../../devel/bonobo
DEPENDS+=		gtkhtml>=0.8:../../www/gtkhtml
DEPENDS+=		gnome-vfs>=0.4.2:../../sysutils/gnome-vfs
DEPENDS+=		libunicode>=0.4:../../textproc/libunicode
DEPENDS+=		oaf>=0.6.1:../../devel/oaf
DEPENDS+=		ORBit>=0.5.6:../../net/ORBit
DEPENDS+=		gnome-print>=0.25:../../print/gnome-print
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
CONFIGURE_ENV+=		CFLAGS="-D_POSIX_THREAD_SYSCALL_SOFT=1 ${CFLAGS}"
CPPFLAGS+=		-D_POSIX_THREAD_SYSCALL_SOFT=1

.include "../../mk/bsd.pkg.mk"
