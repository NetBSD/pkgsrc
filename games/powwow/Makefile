# $NetBSD: Makefile,v 1.9 2007/01/07 09:13:54 rillig Exp $

DISTNAME=	powwow-1.2.5
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://linuz.sns.it/~max/powwow/

MAINTAINER=	jdolecek@NetBSD.org
HOMEPAGE=	http://linuz.sns.it/~max/powwow.html
COMMENT=	Client to play MUDs

USE_TOOLS+=	gmake
POWWOW_DIR=	${PREFIX}/share/powwow

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man6

do-build:
	cd ${WRKSRC} && POWWOW_DIR="${POWWOW_DIR}" CFLAGS="${CFLAGS}" ./make_it

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/powwow ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/powwow.6 ${PREFIX}/${PKGMANDIR}/man6
	${INSTALL_DATA_DIR} ${POWWOW_DIR}
	${INSTALL_DATA} ${WRKSRC}/powwow.doc ${POWWOW_DIR}
	${INSTALL_DATA} ${WRKSRC}/powwow.help ${POWWOW_DIR}

.include "../../mk/bsd.pkg.mk"
