# $NetBSD: Makefile,v 1.26 2008/01/19 09:16:22 wiz Exp $
#

DISTNAME=		mirrormagic-2.0.2
PKGREVISION=		1
CATEGORIES=		games x11
MASTER_SITES=		http://www.artsoft.org/RELEASES/unix/mirrormagic/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.artsoft.org/mirrormagic/
COMMENT=		Nice little puzzle game with color graphics and sound

CONFLICTS=		mirrormagic-sdl-[1-9]*

USE_TOOLS+=		gmake
PLIST_SRC=		${WRKDIR}/PLIST PLIST

# if you change SCORE_PATH, don't forget to change patch-aa, too
SCORE_PATH=		/var/games/mirrormagic

INSTALLATION_DIRS=	bin

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

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
