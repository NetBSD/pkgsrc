# $NetBSD: Makefile,v 1.6 2008/03/04 18:15:08 jlam Exp $
#

DISTNAME=	mdd-20050318
CATEGORIES=	mbone
MASTER_SITES=	http://ftp.espci.fr/pub/mdd/
EXTRACT_SUFX=	.tgz

MAINTAINER=	manu@NetBSD.org
COMMENT=	Multicast file distribution tool

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mdd ${DESTDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/mdd.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

.include "../../mk/bsd.pkg.mk"
