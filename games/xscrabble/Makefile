# $NetBSD: Makefile,v 1.6 2002/10/21 12:22:21 wiz Exp $
#

DISTNAME=	xscrabble
PKGNAME=	xscrabble-1.0
PKGREVISION=	1
CATEGORIES=	games x11
MASTER_SITES=	http://www.belgarath.demon.co.uk/programs/

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://www.belgarath.demon.co.uk/programs/
COMMENT=	X version of the popular board game, for 1 to 4 players

WRKSRC=		${WRKDIR}/xscrabble
DIST_SUBDIR=	${PKGNAME}
USE_BUILDLINK2=	YES
USE_X11BASE=	YES
USE_IMAKE=	YES

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

.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
