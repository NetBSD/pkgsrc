# $NetBSD: Makefile,v 1.7 2005/10/12 09:53:55 wiz Exp $
#

DISTNAME=		queue-fix-1.4
CATEGORIES=		mail
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://www.netmeridian.com/e-huss/
COMMENT=		Check and repair the qmail queue structure

INSTALLATION_DIRS=	bin

DJB_RESTRICTED=		NO

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/queue-fix ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/queue-fix
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/queue-fix

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
