# $NetBSD: Makefile,v 1.1.1.1 2001/05/21 12:52:44 zuntum Exp $
#

DISTNAME=	ipcalc.pl
PKGNAME=	ipcalc-0.33
CATEGORIES=	net
MASTER_SITES=	http://jodies.cx/
EXTRACT_SUFX=	#

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://jodies.de/ipcalc/
COMMENT=	IP Calculator

EXTRACT_CMD=    ${CP} ${DOWNLOADED_DISTFILE} ${WRKSRC}
WRKSRC=         ${WRKDIR}

USE_PERL5=	YES
NO_BUILD=	YES

post-patch:
	${SED} "s,/usr/bin/perl,${LOCALBASE}/bin/perl,"			\
		${WRKSRC}/ipcalc.pl > ${WRKSRC}/ipcalc.pl.done
	${MV} ${WRKSRC}/ipcalc.pl.done ${WRKSRC}/ipcalc.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ipcalc.pl ${PREFIX}/bin/ipcalc

.include "../../mk/bsd.pkg.mk"
