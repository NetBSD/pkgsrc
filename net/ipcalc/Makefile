# $NetBSD: Makefile,v 1.3 2001/12/23 07:57:43 zuntum Exp $
#

DISTNAME=	ipcalc.pl
PKGNAME=	ipcalc-0.34
CATEGORIES=	net
MASTER_SITES=	http://jodies.cx/
EXTRACT_SUFX=	#

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://jodies.de/ipcalc/
COMMENT=	IP Calculator

EXTRACT_CMD=    ${CP} ${DOWNLOADED_DISTFILE} ${WRKSRC}
WRKSRC=         ${WRKDIR}

USE_PERL5=	YES
REPLACE_PERL=	${WRKSRC}/ipcalc.pl
NO_BUILD=	YES

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ipcalc.pl ${PREFIX}/bin/ipcalc

.include "../../mk/bsd.pkg.mk"
