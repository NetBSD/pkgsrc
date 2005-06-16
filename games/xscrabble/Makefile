# $NetBSD: Makefile,v 1.13 2005/06/16 06:57:56 jlam Exp $
#

DISTNAME=	xscrabble-1.0
PKGREVISION=	1
CATEGORIES=	games x11
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	X version of the popular board game, for 1 to 4 players

WRKSRC=		${WRKDIR}/xscrabble
USE_IMAKE=	YES

INSTALLATION_DIRS=	bin lib/X11/app-defaults

post-patch:
	${SED} 's!/usr/local/lib!${PREFIX}/share/games/xscrabble!g' \
		${WRKSRC}/XScrabble.ad > ${WRKSRC}/XScrabble

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/xscrabble ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/xscrab ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/games
	${INSTALL_DATA_DIR} ${PREFIX}/share/games/xscrabble
	${INSTALL_DATA} ${WRKSRC}/OSPD3.gz ${PREFIX}/share/games/xscrabble
	${INSTALL_DATA} ${WRKSRC}/scrabble_permutations ${PREFIX}/share/games/xscrabble
	${INSTALL_DATA} ${WRKSRC}/xscrabble.scores ${PREFIX}/share/games/xscrabble/xscrabble.scores.dist
	${CHOWN} ${BINOWN}:games ${PREFIX}/share/games/xscrabble/xscrabble.scores.dist
	${CHMOD} 0664 ${PREFIX}/share/games/xscrabble/xscrabble.scores.dist
	${INSTALL_DATA} ${WRKSRC}/XScrabble ${PREFIX}/lib/X11/app-defaults
	@if [ ! -f /var/games/xscrabble.scores ]; then \
		${CP} -p ${PREFIX}/share/games/xscrabble/xscrabble.scores.dist \
			/var/games/xscrabble.scores ; \
	fi

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
