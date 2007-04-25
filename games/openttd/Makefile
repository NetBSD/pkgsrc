# $NetBSD: Makefile,v 1.21 2007/04/25 07:32:48 tnn Exp $

DISTNAME=	openttd-0.5.1-source
PKGNAME=	openttd-0.5.1
PKGREVISION=	1
CATEGORIES=	games x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openttd/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.openttd.com/
COMMENT=	Open source clone of Transport Tycoon Deluxe
EXTRACT_SUFX=	.tar.bz2

USE_LANGUAGES+=	c c++
USE_TOOLS+=	gmake pkg-config

DATA_DIR=	${PREFIX}/share/games/openttd

MAKE_ENV+=	PREFIX=${PREFIX:Q}
MAKE_ENV+=	INSTALL=1
MAKE_ENV+=	BINARY_DIR=bin
MAKE_ENV+=	DATA_DIR=share/games/openttd
MAKE_ENV+=	USE_HOMEDIR=1
MAKE_ENV+=	PERSONAL_DIR=.openttd
MAKE_ENV+=	WITH_NETWORK=1
MAKE_ENV+=	X11BASE=${X11BASE:Q}

WRKSRC=		${WRKDIR}/${DISTNAME:S:-source::}

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/openttd ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DATA_DIR}
	${INSTALL_DATA_DIR} ${DATA_DIR}/lang
	${INSTALL_DATA_DIR} ${DATA_DIR}/data
	${INSTALL_DATA_DIR} ${DATA_DIR}/docs
	${INSTALL_DATA_DIR} ${DATA_DIR}/gm
	${INSTALL_DATA} -m 644 ${WRKSRC}/lang/*.lng ${DATA_DIR}/lang
	${INSTALL_DATA} -m 644 ${WRKSRC}/data/* ${DATA_DIR}/data
	${INSTALL_DATA} -m 644 ${WRKSRC}/readme.txt ${DATA_DIR}/docs
	${INSTALL_DATA} -m 644 ${WRKSRC}/changelog.txt ${DATA_DIR}/docs
	${INSTALL_DATA} -m 644 ${WRKSRC}/docs/Manual.txt ${DATA_DIR}/docs
	${INSTALL_DATA} -m 644 ${WRKSRC}/docs/multiplayer.txt ${DATA_DIR}/docs

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
