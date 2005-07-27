# $NetBSD: Makefile,v 1.4 2005/07/27 16:21:17 wiz Exp $
#

DISTNAME=		cmatrix-1.2a
CATEGORIES=		games
MASTER_SITES=		http://www.asty.org/cmatrix/dist/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.asty.org/cmatrix/
COMMENT=		Make your console feel like Nadbuchonazor's bridge

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cmatrix ${PREFIX}/bin/cmatrix
	${INSTALL_MAN} ${WRKSRC}/cmatrix.1 ${PREFIX}/man/man1/cmatrix.1
	${INSTALL_DATA_DIR} ${PREFIX}/share/cmatrix
	${INSTALL_DATA} ${WRKSRC}/mtx.pcf ${PREFIX}/share/cmatrix/mtx.pcf

.include "../../mk/bsd.pkg.mk"
