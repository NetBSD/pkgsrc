# $NetBSD: Makefile,v 1.12 2004/10/03 00:14:46 tv Exp $
#

DISTNAME=		mirrormagic-2.0.2
PKGNAME=		${DISTNAME:S/-/-sdl-/}
PKGREVISION=		6
CATEGORIES=		games x11
MASTER_SITES=		http://www.artsoft.org/RELEASES/unix/mirrormagic/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.artsoft.org/mirrormagic/
COMMENT=		Nice little puzzle game with color graphics and sound

CONFLICTS=		mirrormagic-[1-9]*

USE_BUILDLINK3=		YES
USE_GNU_TOOLS+=		make
PLIST_SRC=		${WRKDIR}/PLIST PLIST

# if you change SCORE_PATH, don't forget to change patch-aa, too
SCORE_PATH=		/var/games/mirrormagic

do-install:
	${INSTALL_PROGRAM} -o bin -g games -m 2755 \
		${WRKSRC}/mirrormagic ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/mirrormagic
	cd ${WRKSRC} && ${PAX} -rw graphics levels music sounds \
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
	${FIND} share/mirrormagic/levels/${levdir} -type f -print >>${WRKDIR}/PLIST
.endfor
.for directory in graphics music sounds
	cd ${PREFIX} && \
	${FIND} share/mirrormagic/${directory} -type f -print >>${WRKDIR}/PLIST
.endfor
	${CHOWN} -R games:games ${SCORE_PATH}

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
