# $NetBSD: Makefile,v 1.9 2003/07/17 22:51:15 grant Exp $

DISTNAME=	ipcalc
PKGNAME=	${DISTNAME}-0.35
DIST_SUBDIR=	${PKGNAME}
WRKSRC=         ${WRKDIR}
CATEGORIES=	net
MASTER_SITES=	http://jodies.de/
EXTRACT_SUFX=	.pl

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://jodies.de/ipcalc/
COMMENT=	IP Calculator

EXTRACT_CMD=    ${CP} ${DOWNLOADED_DISTFILE} ${WRKSRC}

USE_PERL5=	YES
REPLACE_PERL=	ipcalc.pl
NO_BUILD=	YES

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ipcalc.pl ${PREFIX}/bin/ipcalc

.include "../../mk/bsd.pkg.mk"
