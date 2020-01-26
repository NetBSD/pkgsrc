# $NetBSD: Makefile,v 1.11 2020/01/26 17:32:01 rillig Exp $
#

DISTNAME=	pscal-1.16
CATEGORIES=	print
MASTER_SITES=	http://www.panix.com/~mbh/pscal/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.panix.com/~mbh/projects.html
COMMENT=	Produces simple, nice-looking PostScript calendars

INSTALLATION_DIRS=	bin share/doc/pscal

NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pscal ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/pscal

.include "../../mk/bsd.pkg.mk"
