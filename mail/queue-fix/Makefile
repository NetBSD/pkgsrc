# $NetBSD: Makefile,v 1.1.1.1 2004/08/28 22:14:33 schmonz Exp $
#

DISTNAME=		queue-fix
PKGNAME=		${DISTNAME:C/$/-1.4/}
CATEGORIES=		mail
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://www.netmeridian.com/e-huss/
COMMENT=		Check and repair the qmail queue structure

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

USE_BUILDLINK3=		yes

ALL_TARGET=		it

INSTALLATION_DIRS=	bin share/doc/queue-fix

do-configure:
	${ECHO} ${CC} ${CFLAGS} > ${WRKSRC}/conf-cc
	${ECHO} ${CC} ${_STRIPFLAG_CC} > ${WRKSRC}/conf-ld

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/queue-fix ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/queue-fix

.include "../../mk/bsd.pkg.mk"
