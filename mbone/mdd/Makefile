# $NetBSD: Makefile,v 1.8 2018/08/29 00:50:12 manu Exp $
#

DISTNAME=	mdd-20180824
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
