# $NetBSD: Makefile,v 1.1.1.1 2004/12/24 16:51:33 manu Exp $
#

DISTNAME=	mdd-20041224
CATEGORIES=	mbone
MASTER_SITES=	http://ftp.espci.fr/pub/mdd/
EXTRACT_SUFX=	.tgz

MAINTAINER=	manu@netbsd.org
COMMENT=	Multicast file distribution tool

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mdd ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/mdd.1 ${PREFIX}/man/man1/

.include "../../mk/bsd.pkg.mk"
