# $NetBSD: Makefile,v 1.5 1999/05/24 20:39:36 tv Exp $
#

DISTNAME=		gtksql-0.2
CATEGORIES=		databases
MASTER_SITES=		http://www.multimania.com/bbrox/GtkSQL/ \
			ftp://ftp.infodrom.north.de/pub/unix/gtkbuffet/apps/gtksql/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.multimania.com/bbrox/GtkSQL/

DEPENDS+=		gtk10-1.0.6:../../x11/gtk10
DEPENDS+=		postgresql-6.4.2:../../databases/postgresql

USE_X11BASE=

PGUSER?=		pgsql

post-patch:
	${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.bak
	${SED} -e 's|@PGUSER@|${PGUSER}|g' < ${WRKSRC}/Makefile.bak \
		> ${WRKSRC}/Makefile

.include "../../mk/bsd.pkg.mk"
