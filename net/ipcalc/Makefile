# $NetBSD: Makefile,v 1.14 2006/10/04 21:53:16 wiz Exp $

DISTNAME=	ipcalc-0.40
CATEGORIES=	net
MASTER_SITES=	http://jodies.de/ipcalc-archive/

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://jodies.de/ipcalc
COMMENT=	IP Calculator

USE_TOOLS+=	perl:run
REPLACE_PERL=	ipcalc
NO_BUILD=	YES

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ipcalc ${PREFIX}/bin/ipcalc

.include "../../mk/bsd.pkg.mk"
