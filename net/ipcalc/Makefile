# $NetBSD: Makefile,v 1.15 2007/07/24 17:23:34 jschauma Exp $

DISTNAME=	ipcalc-0.41
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
