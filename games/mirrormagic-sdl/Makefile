# $NetBSD: Makefile,v 1.1.1.1 2002/09/12 00:18:27 wiz Exp $
#

DISTNAME=		mirrormagic-2.0.1
PKGNAME=		${DISTNAME:S/-/-sdl-/}
CATEGORIES=		games x11
MASTER_SITES=		http://www.artsoft.org/RELEASES/unix/mirrormagic/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.artsoft.org/mirrormagic/
COMMENT=		Nice little puzzle game with color graphics and sound

CONFLICTS=		mirrormagic-[1-9]*

USE_BUILDLINK2=		YES
USE_GMAKE=		YES
PLIST_SRC=		${WRKDIR}/PLIST PLIST

# if you change SCORE_PATH, don't forget to change patch-aa, too
SCORE_PATH=		/var/games/mirrormagic

do-install:
	${INSTALL_PROGRAM} -o bin -g games -m 2755 \
		${WRKSRC}/mirrormagic ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/mirrormagic
	cd ${WRKSRC} && ${PAX} -r -w graphics levels music sounds \
		${PREFIX}/share/mirrormagic/
	${CHOWN} -R games:games ${PREFIX}/share/mirrormagic
	${INSTALL_DATA_DIR} ${SCORE_PATH}/scores
	${CHMOD} 755 ${SCORE_PATH}
	${CHMOD} 775 ${SCORE_PATH}/scores
.for directory in classic_deflektor classic_mindbender
		${INSTALL_DATA_DIR} ${SCORE_PATH}/scores/${directory} \
		&& ${CHMOD} 775 ${SCORE_PATH}/scores/${directory}
.endfor
	${RM} -f ${WRKDIR}/PLIST
.for levdir in Classic_Games
	cd ${PREFIX} && \
	${FIND} share/mirrormagic/levels/${levdir} -type f >>${WRKDIR}/PLIST
.endfor
.for directory in graphics music sounds
	cd ${PREFIX} && \
	${FIND} share/mirrormagic/${directory} -type f >>${WRKDIR}/PLIST
.endfor
	${CHOWN} -R games:games ${SCORE_PATH}

.include "../../audio/SDL-mixer/buildlink2.mk"
.include "../../graphics/SDL-image/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
