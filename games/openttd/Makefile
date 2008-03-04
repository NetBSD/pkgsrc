# $NetBSD: Makefile,v 1.25 2008/03/04 04:05:30 tnn Exp $

DISTNAME=	openttd-0.5.3-source
PKGNAME=	openttd-0.5.3
CATEGORIES=	games x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openttd/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.openttd.com/
COMMENT=	Open source clone of Transport Tycoon Deluxe
EXTRACT_SUFX=	.tar.bz2

PKG_DESTDIR_SUPPORT=	user-destdir
USE_LANGUAGES+=	c c++
USE_TOOLS+=	gmake pkg-config

DATA_DIR=	${DESTDIR}${PREFIX}/share/games/openttd

MAKE_ENV+=	PREFIX=${PREFIX:Q}
MAKE_ENV+=	INSTALL=1
MAKE_ENV+=	BINARY_DIR=bin
MAKE_ENV+=	DATA_DIR=share/games/openttd
MAKE_ENV+=	USE_HOMEDIR=1
MAKE_ENV+=	PERSONAL_DIR=.openttd
MAKE_ENV+=	WITH_NETWORK=1
MAKE_ENV+=	X11BASE=${X11BASE:Q}

# disable custom assert for Mac OS X
CFLAGS+=	-DNDEBUG=1

WRKSRC=		${WRKDIR}/${DISTNAME:S:-source::}

.include "options.mk"

INSTALLATION_DIRS=	bin share/games/openttd/data share/games/openttd/docs \
			  share/games/openttd/lang share/games/openttd/gm

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/openttd ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} -m 644 ${WRKSRC}/lang/*.lng ${DATA_DIR}/lang
	${INSTALL_DATA} -m 644 ${WRKSRC}/data/* ${DATA_DIR}/data
	${INSTALL_DATA} -m 644 ${WRKSRC}/readme.txt ${DATA_DIR}/docs
	${INSTALL_DATA} -m 644 ${WRKSRC}/changelog.txt ${DATA_DIR}/docs
	${INSTALL_DATA} -m 644 ${WRKSRC}/docs/Manual.txt ${DATA_DIR}/docs
	${INSTALL_DATA} -m 644 ${WRKSRC}/docs/multiplayer.txt ${DATA_DIR}/docs
.if !empty(PKG_OPTIONS:Mttd-data)
	${RUN} for f in ${DATAFILES}; do \
	  ${INSTALL_DATA} ${WRKDIR}/$$f ${DATA_DIR}/data; done
	${RUN} for f in ${GMFILES}; do \
	  ${INSTALL_DATA} ${WRKDIR}/$$f ${DATA_DIR}/gm; done
.endif

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
