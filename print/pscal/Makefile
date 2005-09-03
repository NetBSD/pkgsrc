# $NetBSD: Makefile,v 1.7 2005/09/03 15:56:03 recht Exp $
#

DISTNAME=	pscal-1.16
CATEGORIES=	print
MASTER_SITES=	http://www.panix.com/~mbh/pscal/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.panix.com/~mbh/projects.html
COMMENT=	Produces simple, nice-looking PostScript calendars

INSTALLATION_DIRS=	bin

do-build:

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pscal ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/pscal
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/pscal

.include "../../mk/bsd.pkg.mk"
