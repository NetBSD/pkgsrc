# $NetBSD: Makefile,v 1.4 2002/02/10 21:50:49 zuntum Exp $
#

DISTNAME=	ipcalc-0.35
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	#

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://jodies.de/ipcalc/
COMMENT=	IP Calculator

EXTRACT_CMD=    ${CP} ${DOWNLOADED_DISTFILE} ${WRKSRC}
WRKSRC=         ${WRKDIR}

USE_PERL5=	YES
REPLACE_PERL=	${WRKSRC}/${DISTNAME}
NO_BUILD=	YES

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} ${PREFIX}/bin/ipcalc

.include "../../mk/bsd.pkg.mk"
