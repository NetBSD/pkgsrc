# $NetBSD: Makefile,v 1.8 2002/08/25 21:49:22 jlam Exp $
#

DISTNAME=	unace-1.2b
PKGNAME=	unace-1.2.2
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SUNSITE:=utils/compress/}

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://www.winace.com/
COMMENT=	Extract, list and test files in ACE archives

USE_BUILDLINK2=	yes
USE_GMAKE=	yes

ALL_TARGET=	clean unace

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unace ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/unace
	${INSTALL_MAN} ${WRKSRC}/readme.txt ${PREFIX}/share/doc/unace

.include "../../mk/bsd.pkg.mk"
