# $NetBSD: Makefile,v 1.11 1999/12/02 01:47:04 darcy Exp $
#

DISTNAME=		gtksql-0.3
CATEGORIES=		databases
MASTER_SITES=		http://www.multimania.com/bbrox/GtkSQL/ \
			${MASTER_SITE_SUNSITE:=X11/gtkbuffet/apps/gtksql/} \
			ftp://ftp.infodrom.north.de/pub/unix/gtkbuffet/apps/gtksql/ \
			ftp://ftp.loxinfo.co.th/pub/unix/database/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.multimania.com/bbrox/GtkSQL/

DEPENDS+=		gtk+-1.2.*:../../x11/gtk
DEPENDS+=		postgresql-6.5.3:../../databases/postgresql

USE_X11BASE=

.include "../../mk/bsd.prefs.mk"
PGUSER?=		pgsql

post-patch:
	${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.bak
	${SED} -e 's|@PGUSER@|${PGUSER}|g' < ${WRKSRC}/Makefile.bak \
		> ${WRKSRC}/Makefile

.include "../../mk/bsd.pkg.mk"
