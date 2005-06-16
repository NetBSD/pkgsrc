# $NetBSD: Makefile,v 1.5 2005/06/16 06:57:55 jlam Exp $

DISTNAME=	openttd-0.3.6-source
PKGNAME=	openttd-0.3.6
CATEGORIES=	games x11
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=openttd/}

MAINTAINER=	froz@icix.org
HOMEPAGE=	http://www.openttd.com/
COMMENT=	Open source clone of Transport Tycoon Deluxe

USE_TOOLS+=	gmake

DATA_DIR= 	${PREFIX}/share/games/openttd

MAKE_ENV+=	PREFIX=${PREFIX}
MAKE_ENV+=	INSTALL=1
MAKE_ENV+=	BINARY_DIR=bin
MAKE_ENV+=	DATA_DIR=share/games/openttd
MAKE_ENV+=	USE_HOMEDIR=1
MAKE_ENV+=	PERSONAL_DIR=.openttd
MAKE_ENV+=	WITH_NETWORK=1
MAKE_ENV+=	X11BASE=${X11BASE}

WRKSRC=		${WRKDIR}/${PKGNAME}

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/openttd ${PREFIX}/bin
	@${INSTALL_DATA_DIR} ${DATA_DIR}
	@${INSTALL_DATA_DIR} ${DATA_DIR}/lang
	@${INSTALL_DATA_DIR} ${DATA_DIR}/data
	@${INSTALL_DATA_DIR} ${DATA_DIR}/docs
	@${INSTALL_DATA_DIR} ${DATA_DIR}/gm
	${INSTALL_DATA} -m 644 ${WRKSRC}/lang/*.lng ${DATA_DIR}/lang
	${INSTALL_DATA} -m 644 ${WRKSRC}/data/* ${DATA_DIR}/data
	${INSTALL_DATA} -m 644 ${WRKSRC}/readme.txt ${DATA_DIR}/docs
	${INSTALL_DATA} -m 644 ${WRKSRC}/changelog.txt ${DATA_DIR}/docs
	${INSTALL_DATA} -m 644 ${WRKSRC}/docs/Manual.txt ${DATA_DIR}/docs
	${INSTALL_DATA} -m 644 ${WRKSRC}/docs/multiplayer.txt ${DATA_DIR}/docs

.include "../../graphics/png/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
