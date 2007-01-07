# $NetBSD: Makefile,v 1.5 2007/01/07 09:14:00 rillig Exp $
#

DISTNAME=	mdd-20050318
CATEGORIES=	mbone
MASTER_SITES=	http://ftp.espci.fr/pub/mdd/
EXTRACT_SUFX=	.tgz

MAINTAINER=	manu@NetBSD.org
COMMENT=	Multicast file distribution tool

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mdd ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/mdd.1 ${PREFIX}/${PKGMANDIR}/man1/

.include "../../mk/bsd.pkg.mk"
