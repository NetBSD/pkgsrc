# $NetBSD: Makefile,v 1.9 2012/10/08 12:19:29 asau Exp $
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
	${INSTALL_PROGRAM} ${WRKSRC}/queue-fix ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/queue-fix
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/queue-fix

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
