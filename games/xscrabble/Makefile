# $NetBSD: Makefile,v 1.24 2012/10/06 11:55:03 asau Exp $
#

DISTNAME=	xscrabble-1.0
PKGREVISION=	7
CATEGORIES=	games x11
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	X version of the popular board game, for 1 to 4 players

WRKSRC=		${WRKDIR}/xscrabble
USE_IMAKE=	YES

INSTALLATION_DIRS=	bin lib/X11/app-defaults

SUBST_CLASSES+=		xscrabble
SUBST_FILES.xscrabble=	XScrabble.ad
SUBST_STAGE.xscrabble=	pre-configure
SUBST_SED.xscrabble=	-e 's,/usr/local/lib/xscrabble\.scores,${VARBASE}/games/xscrabble.scores,g'
SUBST_SED.xscrabble+=	-e 's,/usr/local/lib,${PREFIX}/share/games/xscrabble,g'

MAKE_DIRS=		${VARBASE}/games
EGDIR=			${PREFIX}/share/games/xscrabble

SETGIDGAME=		yes
CONF_FILES_PERMS=	${EGDIR}/xscrabble.scores.dist \
			${VARBASE}/games/xscrabble.scores \
			${GAMES_USER} ${GAMES_GROUP} ${GAMEDATAMODE}
SPECIAL_PERMS=		bin/xscrab ${SETGID_GAMES_PERMS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/xscrabble ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/xscrab ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/games
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/games/xscrabble
	${INSTALL_DATA} ${WRKSRC}/OSPD3.gz ${DESTDIR}${EGDIR}/
	${INSTALL_DATA} ${WRKSRC}/scrabble_permutations ${DESTDIR}${EGDIR}/
	${INSTALL_DATA} ${WRKSRC}/xscrabble.scores \
		${DESTDIR}${EGDIR}/xscrabble.scores.dist
	${INSTALL_DATA} ${WRKSRC}/XScrabble.ad \
		${DESTDIR}${PREFIX}/lib/X11/app-defaults/XScrabble

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
