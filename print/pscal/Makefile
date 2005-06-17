# $NetBSD: Makefile,v 1.6 2005/06/17 03:50:30 jlam Exp $
#

DISTNAME=	pscal-1.15
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
