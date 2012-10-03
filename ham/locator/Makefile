# $NetBSD: Makefile,v 1.7 2012/10/03 13:01:45 asau Exp $
#

DISTNAME=	locator-0.1
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_SUNSITE:=apps/ham/}

MAINTAINER=	dawszy@arhea.net
HOMEPAGE=	http://www.stauss.purespace.de/
COMMENT=	Longitudes, latitudes to HAM locator converter

NO_CONFIGURE=	yes

INSTALLATION_DIRS=	bin

USE_LANGUAGES=	c++

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/locator ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
