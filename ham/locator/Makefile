# $NetBSD: Makefile,v 1.4 2005/06/16 06:57:59 jlam Exp $
#

DISTNAME=	locator-0.1
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_SUNSITE:=apps/ham/}

MAINTAINER=	dawszy@arhea.net
HOMEPAGE=	http://www.stauss.purespace.de/
COMMENT=	Longitudes, latitudes to HAM locator converter

NO_CONFIGURE=	yes

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/locator ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
