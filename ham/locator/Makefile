# $NetBSD: Makefile,v 1.1.1.1 2002/04/19 15:38:21 zuntum Exp $
#

DISTNAME=	locator-0.1
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_SUNSITE:=apps/ham/}

MAINTAINER=	dawszy@arhea.net
HOMEPAGE=	http://www.stauss.purespace.de/
COMMENT=	longitudes, latitudes to HAM locator converter

NO_CONFIGURE=	yes
NO_PATCH=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/locator ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
