# $NetBSD: Makefile,v 1.4 2005/10/10 17:09:39 hira Exp $
#

DISTNAME=	mdd-20050318
CATEGORIES=	mbone
MASTER_SITES=	http://ftp.espci.fr/pub/mdd/
EXTRACT_SUFX=	.tgz

MAINTAINER=	manu@NetBSD.org
COMMENT=	Multicast file distribution tool

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mdd ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/mdd.1 ${PREFIX}/man/man1/

.include "../../mk/bsd.pkg.mk"
