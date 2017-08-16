# $NetBSD: Makefile,v 1.8 2017/08/16 20:45:40 wiz Exp $
#

DISTNAME=	locator-0.1
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_SUNSITE:=apps/ham/}

MAINTAINER=	dawszy@arhea.net
#HOMEPAGE=	http://www.stauss.purespace.de/
COMMENT=	Longitudes, latitudes to HAM locator converter

NO_CONFIGURE=	yes

INSTALLATION_DIRS=	bin

USE_LANGUAGES=	c++

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/locator ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
