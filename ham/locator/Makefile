# $NetBSD: Makefile,v 1.2 2003/03/28 21:14:22 wiz Exp $
#

DISTNAME=	locator-0.1
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_SUNSITE:=apps/ham/}

MAINTAINER=	dawszy@arhea.net
HOMEPAGE=	http://www.stauss.purespace.de/
COMMENT=	longitudes, latitudes to HAM locator converter

NO_CONFIGURE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/locator ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
