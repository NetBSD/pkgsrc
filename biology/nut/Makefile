# $NetBSD: Makefile,v 1.1.1.1 2000/01/11 02:56:33 garbled Exp $

DISTNAME=	nut4
PKGNAME=	nut-4.0
WRKSRC=		${WRKDIR}/nut
CATEGORIES=	biology
MASTER_SITES=	http://www.kachinatech.com/~hjjou/archives/

MAINTAINER=	root@garbled.net

ALL_TARGET=	nut
USE_GMAKE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nut ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/nut
	${INSTALL_DATA} ${WRKSRC}/nutdb/abbrev.txt ${PREFIX}/share/nut/abbrev.txt

.include "../../mk/bsd.pkg.mk"
