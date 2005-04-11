# $NetBSD: Makefile,v 1.5 2005/04/11 21:46:27 tv Exp $
#

DISTNAME=		queue-fix
PKGNAME=		${DISTNAME:C/$/-1.4/}
CATEGORIES=		mail
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://www.netmeridian.com/e-huss/
COMMENT=		Check and repair the qmail queue structure

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}


INSTALLATION_DIRS=	bin share/doc/queue-fix

DJB_RESTRICTED=		NO

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/queue-fix ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/queue-fix

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
