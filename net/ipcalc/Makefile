# $NetBSD: Makefile,v 1.8 2003/03/29 12:41:57 jmmv Exp $

DISTNAME=	ipcalc
PKGNAME=	${DISTNAME}-0.35
DIST_SUBDIR=	${PKGNAME}
WRKSRC=         ${WRKDIR}
CATEGORIES=	net
MASTER_SITES=	http://jodies.de/
EXTRACT_SUFX=	.pl

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://jodies.de/ipcalc/
COMMENT=	IP Calculator

EXTRACT_CMD=    ${CP} ${DOWNLOADED_DISTFILE} ${WRKSRC}

USE_PERL5=	YES
REPLACE_PERL=	ipcalc.pl
NO_BUILD=	YES

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ipcalc.pl ${PREFIX}/bin/ipcalc

.include "../../mk/bsd.pkg.mk"
