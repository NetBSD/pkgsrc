# $NetBSD: Makefile,v 1.2 2004/12/03 15:15:02 wiz Exp $
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

BUILD_TARGET=		it

INSTALLATION_DIRS=	bin share/doc/queue-fix

do-configure:
	${ECHO} ${CC} ${CFLAGS} > ${WRKSRC}/conf-cc
	${ECHO} ${CC} ${_STRIPFLAG_CC} > ${WRKSRC}/conf-ld

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/queue-fix ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/queue-fix

.include "../../mk/bsd.pkg.mk"
