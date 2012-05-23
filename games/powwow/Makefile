# $NetBSD: Makefile,v 1.15 2012/05/23 06:23:02 dholland Exp $

DISTNAME=	powwow-1.2.5
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://hoopajoo.net/static/powwow-mirror/powwow/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://hoopajoo.net/projects/powwow.html
COMMENT=	Client to play MUDs

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake
POWWOW_DIR=	${PREFIX}/share/powwow

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man6

do-build:
	cd ${WRKSRC} && POWWOW_DIR=${POWWOW_DIR} CFLAGS=${CFLAGS:Q} \
		LDFLAGS=${LDFLAGS:Q} ./make_it

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/powwow ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/powwow.6 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man6
	${INSTALL_DATA_DIR} ${DESTDIR}${POWWOW_DIR}
	${INSTALL_DATA} ${WRKSRC}/powwow.doc ${DESTDIR}${POWWOW_DIR}
	${INSTALL_DATA} ${WRKSRC}/powwow.help ${DESTDIR}${POWWOW_DIR}

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
