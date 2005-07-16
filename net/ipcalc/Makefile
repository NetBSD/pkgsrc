# $NetBSD: Makefile,v 1.13 2005/07/16 01:19:15 jlam Exp $

DISTNAME=	ipcalc-0.40
CATEGORIES=	net
MASTER_SITES=	http://jodies.de/ipcalc-archive/

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://jodies.de/ipcalc/
COMMENT=	IP Calculator

USE_TOOLS+=	perl:run
REPLACE_PERL=	ipcalc
NO_BUILD=	YES

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ipcalc ${PREFIX}/bin/ipcalc

.include "../../mk/bsd.pkg.mk"
