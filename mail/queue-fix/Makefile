# $NetBSD: Makefile,v 1.8 2008/03/04 17:57:19 jlam Exp $
#

DISTNAME=		queue-fix-1.4
CATEGORIES=		mail
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://www.netmeridian.com/e-huss/
COMMENT=		Check and repair the qmail queue structure

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS=	bin

DJB_RESTRICTED=		NO

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/queue-fix ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/queue-fix
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/queue-fix

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
