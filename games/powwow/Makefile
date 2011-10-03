# $NetBSD: Makefile,v 1.13 2011/10/03 04:37:05 dholland Exp $

DISTNAME=	powwow-1.2.5
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://hoopajoo.net/static/powwow-mirror/powwow/

MAINTAINER=	jdolecek@NetBSD.org
HOMEPAGE=	http://hoopajoo.net/projects/powwow.html
COMMENT=	Client to play MUDs

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake
POWWOW_DIR=	${PREFIX}/share/powwow

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man6

do-build:
	cd ${WRKSRC} && POWWOW_DIR=${POWWOW_DIR} CFLAGS=${CFLAGS:Q} ./make_it

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/powwow ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/powwow.6 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man6
	${INSTALL_DATA_DIR} ${DESTDIR}${POWWOW_DIR}
	${INSTALL_DATA} ${WRKSRC}/powwow.doc ${DESTDIR}${POWWOW_DIR}
	${INSTALL_DATA} ${WRKSRC}/powwow.help ${DESTDIR}${POWWOW_DIR}

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
