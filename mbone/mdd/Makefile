# $NetBSD: Makefile,v 1.7 2012/10/08 09:25:50 asau Exp $
#

DISTNAME=	mdd-20050318
CATEGORIES=	mbone
MASTER_SITES=	http://ftp.espci.fr/pub/mdd/
EXTRACT_SUFX=	.tgz

MAINTAINER=	manu@NetBSD.org
COMMENT=	Multicast file distribution tool

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mdd ${DESTDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/mdd.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

.include "../../mk/bsd.pkg.mk"
