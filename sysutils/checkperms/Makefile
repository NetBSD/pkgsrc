# $NetBSD: Makefile,v 1.2 2006/11/02 02:40:29 rillig Exp $
#

DISTNAME=	checkperms-1.3
CATEGORIES=	sysutils
MASTER_SITES=	http://www.schlechte-software.de/checkperms/

MAINTAINER=	rillig@NetBSD.org
HOMEPAGE=	http://www.schlechte-software.de/checkperms/
COMMENT=	Check and correct file permissions

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/checkperms ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/checkperms.1 ${PREFIX}/${PKGMANDIR}/man1/

.include "../../mk/bsd.pkg.mk"
