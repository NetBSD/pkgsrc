# $NetBSD: Makefile,v 1.4 2004/01/24 13:30:56 grant Exp $
#

DISTNAME=	powwow-1.2.4
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SUNSITE:=games/muds/}	\
		ftp://Linuz.sns.it/pub/Linux/max/powwow/

MAINTAINER=	jdolecek@NetBSD.org
HOMEPAGE=	http://Linuz.sns.it/~max/powwow.html
COMMENT=	Client to play MUDs

USE_GNU_TOOLS+=	make
POWWOW_DIR=	${PREFIX}/share/powwow

do-build:
	cd ${WRKSRC} && POWWOW_DIR="${POWWOW_DIR}" ./make_it

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/powwow ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/powwow.6 ${PREFIX}/man/man6
	${INSTALL_DATA_DIR} ${POWWOW_DIR}
	${INSTALL_DATA} ${WRKSRC}/powwow.doc ${POWWOW_DIR}
	${INSTALL_DATA} ${WRKSRC}/powwow.help ${POWWOW_DIR}

.include "../../mk/bsd.pkg.mk"
