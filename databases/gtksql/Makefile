# $NetBSD: Makefile,v 1.1.1.1 1999/01/04 13:08:47 frueauf Exp $
#

DISTNAME=	gtksql-0.2
CATEGORIES=	databases
MASTER_SITES=	http://www.multimania.com/bbrox/GtkSQL/ \
		ftp://ftp.infodrom.north.de/pub/unix/gtkbuffet/apps/gtksql/

MAINTAINER=	packages@NetBSD.org
HOMEPAGE=	http://www.multimania.com/bbrox/GtkSQL/

DEPENDS+=	gtk+-1.0.6:../../x11/gtk10
DEPENDS+=	postgresql-6.4.2:../../databases/postgresql

USE_X11=	yes

PGUSER?=	pgsql

post-patch:
	${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.bak
	${SED} -e 's|@PGUSER@|${PGUSER}|g' < ${WRKSRC}/Makefile.bak \
		> ${WRKSRC}/Makefile

.include "../../mk/bsd.pkg.mk"
