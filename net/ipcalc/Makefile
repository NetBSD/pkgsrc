# $NetBSD: Makefile,v 1.12 2005/07/10 21:48:32 seb Exp $

DISTNAME=	ipcalc-0.40
CATEGORIES=	net
MASTER_SITES=	http://jodies.de/ipcalc-archive/

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://jodies.de/ipcalc/
COMMENT=	IP Calculator

USE_PERL5=	YES
REPLACE_PERL=	ipcalc
NO_BUILD=	YES

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ipcalc ${PREFIX}/bin/ipcalc

.include "../../mk/bsd.pkg.mk"
