# $NetBSD: Makefile,v 1.4 1999/02/19 14:28:08 rh Exp $
#

DISTNAME=	gtksql-0.2
CATEGORIES=	databases
MASTER_SITES=	http://www.multimania.com/bbrox/GtkSQL/ \
		ftp://ftp.infodrom.north.de/pub/unix/gtkbuffet/apps/gtksql/

MAINTAINER=	packages@NetBSD.org
HOMEPAGE=	http://www.multimania.com/bbrox/GtkSQL/

DEPENDS+=	gtk10-1.0.6:../../x11/gtk10
DEPENDS+=	postgresql-6.4.2:../../databases/postgresql

# restriction inherit from postgresql
NOT_FOR_ARCHS=	alpha mips

USE_X11BASE=	yes

PGUSER?=	pgsql

post-patch:
	${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.bak
	${SED} -e 's|@PGUSER@|${PGUSER}|g' < ${WRKSRC}/Makefile.bak \
		> ${WRKSRC}/Makefile

.include "../../mk/bsd.pkg.mk"
