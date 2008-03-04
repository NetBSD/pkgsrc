# $NetBSD: Makefile,v 1.10 2008/03/04 06:59:05 jlam Exp $

DISTNAME=	powwow-1.2.5
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://linuz.sns.it/~max/powwow/

MAINTAINER=	jdolecek@NetBSD.org
HOMEPAGE=	http://linuz.sns.it/~max/powwow.html
COMMENT=	Client to play MUDs

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake
POWWOW_DIR=	${PREFIX}/share/powwow

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man6

do-build:
	cd ${WRKSRC} && POWWOW_DIR="${POWWOW_DIR}" CFLAGS="${CFLAGS}" ./make_it

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/powwow ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/powwow.6 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man6
	${INSTALL_DATA_DIR} ${DESTDIR}${POWWOW_DIR}
	${INSTALL_DATA} ${WRKSRC}/powwow.doc ${DESTDIR}${POWWOW_DIR}
	${INSTALL_DATA} ${WRKSRC}/powwow.help ${DESTDIR}${POWWOW_DIR}

.include "../../mk/bsd.pkg.mk"
