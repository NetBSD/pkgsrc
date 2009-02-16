# $NetBSD: Makefile,v 1.16 2009/02/16 18:39:36 joerg Exp $

DISTNAME=	ipcalc-0.41
CATEGORIES=	net
MASTER_SITES=	http://jodies.de/ipcalc-archive/

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://jodies.de/ipcalc
COMMENT=	IP Calculator

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	perl:run
REPLACE_PERL=	ipcalc
NO_BUILD=	YES

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ipcalc ${DESTDIR}${PREFIX}/bin/ipcalc

.include "../../mk/bsd.pkg.mk"
