# $NetBSD: Makefile,v 1.3 2003/07/21 16:52:08 martti Exp $
#

DISTNAME=	locator-0.1
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_SUNSITE:=apps/ham/}

MAINTAINER=	dawszy@arhea.net
HOMEPAGE=	http://www.stauss.purespace.de/
COMMENT=	Longitudes, latitudes to HAM locator converter

NO_CONFIGURE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/locator ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
