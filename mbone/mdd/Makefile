# $NetBSD: Makefile,v 1.3 2005/06/17 03:50:20 jlam Exp $
#

DISTNAME=	mdd-20050318
CATEGORIES=	mbone
MASTER_SITES=	http://ftp.espci.fr/pub/mdd/
EXTRACT_SUFX=	.tgz

MAINTAINER=	manu@netbsd.org
COMMENT=	Multicast file distribution tool

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mdd ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/mdd.1 ${PREFIX}/man/man1/

.include "../../mk/bsd.pkg.mk"
