# $NetBSD: Makefile,v 1.11 2005/06/17 03:50:25 jlam Exp $

DISTNAME=	ipcalc
PKGNAME=	${DISTNAME}-0.35
DIST_SUBDIR=	${PKGNAME}
CATEGORIES=	net
MASTER_SITES=	http://jodies.de/
EXTRACT_SUFX=	.pl

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://jodies.de/ipcalc/
COMMENT=	IP Calculator

EXTRACT_CMD=    ${CP} ${DOWNLOADED_DISTFILE} ${WRKSRC}

WRKSRC=         ${WRKDIR}
USE_PERL5=	YES
REPLACE_PERL=	ipcalc.pl
NO_BUILD=	YES

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ipcalc.pl ${PREFIX}/bin/ipcalc

.include "../../mk/bsd.pkg.mk"
