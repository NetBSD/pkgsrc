# $NetBSD: Makefile,v 1.2 2002/02/13 18:45:55 jdolecek Exp $
#

DISTNAME=	powwow-1.2.4
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SUNSITE:=games/muds/}	\
		ftp://Linuz.sns.it/pub/Linux/max/powwow/

MAINTAINER=	jdolecek@netbsd.org
HOMEPAGE=	http://Linuz.sns.it/~max/powwow.html
COMMENT=	Client to play MUDs

USE_GMAKE=	# defined
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
