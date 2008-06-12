# $NetBSD: Makefile,v 1.9 2008/06/12 02:14:43 joerg Exp $
#

DISTNAME=	pscal-1.16
CATEGORIES=	print
MASTER_SITES=	http://www.panix.com/~mbh/pscal/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.panix.com/~mbh/projects.html
COMMENT=	Produces simple, nice-looking PostScript calendars

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	bin share/doc/pscal

NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pscal ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/pscal

.include "../../mk/bsd.pkg.mk"
