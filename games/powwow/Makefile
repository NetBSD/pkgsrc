# $NetBSD: Makefile,v 1.5 2005/02/04 09:38:43 adam Exp $

DISTNAME=	powwow-1.2.5
CATEGORIES=	games
MASTER_SITES=	http://linuz.sns.it/~max/powwow/

MAINTAINER=	jdolecek@NetBSD.org
HOMEPAGE=	http://linuz.sns.it/~max/powwow.html
COMMENT=	Client to play MUDs

USE_GNU_TOOLS+=	make
POWWOW_DIR=	${PREFIX}/share/powwow

do-build:
	cd ${WRKSRC} && POWWOW_DIR="${POWWOW_DIR}" CFLAGS="${CFLAGS}" ./make_it

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/powwow ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/powwow.6 ${PREFIX}/man/man6
	${INSTALL_DATA_DIR} ${POWWOW_DIR}
	${INSTALL_DATA} ${WRKSRC}/powwow.doc ${POWWOW_DIR}
	${INSTALL_DATA} ${WRKSRC}/powwow.help ${POWWOW_DIR}

.include "../../mk/bsd.pkg.mk"
