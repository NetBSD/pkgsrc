# $NetBSD: Makefile,v 1.5.2.1 2002/06/23 18:55:26 jlam Exp $

DISTNAME=	ipcalc
PKGNAME=	${DISTNAME}-0.35
DIST_SUBDIR=	${PKGNAME}
CATEGORIES=	net
MASTER_SITES=	http://jodies.de/
EXTRACT_SUFX=	.pl

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
