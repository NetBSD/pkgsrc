# $NetBSD: Makefile,v 1.1.1.1 1999/08/26 00:22:53 dmcmahill Exp $
#

DISTNAME=	xscrabble
PKGNAME=	xscrabble-1.0
CATEGORIES=	games x11
MASTER_SITES=	http://www.belgarath.demon.co.uk/programs/

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://www.belgarath.demon.co.uk/programs/

WRKSRC=		${WRKDIR}/xscrabble
USE_X11BASE=	yes
USE_IMAKE=	yes

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
	chown ${BINOWN}:games ${PREFIX}/share/games/xscrabble/xscrabble.scores.dist
	chmod 0664 ${PREFIX}/share/games/xscrabble/xscrabble.scores.dist
	${INSTALL_DATA} ${WRKSRC}/XScrabble ${PREFIX}/lib/X11/app-defaults
	@if [ ! -f /var/games/xscrabble.scores ]; then \
		${CP} -p ${PREFIX}/share/games/xscrabble/xscrabble.scores.dist \
			/var/games/xscrabble.scores ; \
	fi

.include "../../mk/bsd.pkg.mk"
