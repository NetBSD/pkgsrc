# $NetBSD: Makefile,v 1.12 2001/07/05 22:13:06 kristerw Exp $
#

DISTNAME=		mirrormagic-2.0.0
CATEGORIES=		games x11
MASTER_SITES=		http://www.artsoft.org/RELEASES/unix/mirrormagic/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.artsoft.org/mirrormagic/
COMMENT=		Nice little puzzle game with color graphics and sound

USE_GMAKE=		YES

# if you change SCORE_PATH, don't forget to change patch-aa, too
SCORE_PATH=		/var/games/mirrormagic

do-install:
	${INSTALL_PROGRAM} -o bin -g games -m 2755 \
		${WRKSRC}/mirrormagic ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/mirrormagic
	cd ${WRKSRC} && ${PAX} -r -w sounds graphics levels \
		${PREFIX}/share/mirrormagic/
	${CHOWN} -R games:games ${PREFIX}/share/mirrormagic
	${INSTALL_DATA_DIR} ${SCORE_PATH}/scores
	${CHMOD} 755 ${SCORE_PATH}
	${CHMOD} 775 ${SCORE_PATH}/scores
.for directory in classic_deflektor classic_mindbender
		${INSTALL_DATA_DIR} ${SCORE_PATH}/scores/${directory} \
		&& ${CHMOD} 775 ${SCORE_PATH}/scores/${directory}
.endfor
	${CHOWN} -R games:games ${SCORE_PATH}

.include "../../mk/bsd.pkg.mk"
