# $NetBSD: Makefile,v 1.19 2012/10/23 17:18:28 asau Exp $

DISTNAME=	ipcalc-0.41
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://jodies.de/ipcalc-archive/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://jodies.de/ipcalc
COMMENT=	IP Calculator

USE_TOOLS+=	perl:run
REPLACE_PERL=	ipcalc
NO_BUILD=	YES

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ipcalc ${DESTDIR}${PREFIX}/bin/ipcalc

.include "../../mk/bsd.pkg.mk"
