# $NetBSD: Makefile,v 1.1.1.1 2000/01/03 17:23:26 wiz Exp $
#

DISTNAME=		rocksndiamonds-1.4.0
CATEGORIES=		games x11
MASTER_SITES=		http://www.artsoft.org/rocksndiamonds/RELEASES/

MAINTAINER=		wiz@netbsd.org
HOMEPAGE=		http://www.artsoft.org/rocksndiamonds/

USE_GMAKE=		YES

# if you change SCORE_PATH, don't forget to change patch-aa, too
SCORE_PATH=		/var/games/rocksndiamonds

do-install:
	${INSTALL_PROGRAM} -o ${BINOWN} -g games -m 2755 \
		${WRKSRC}/rocksndiamonds ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/rocksndiamonds.1 ${PREFIX}/man/man1/
	${MKDIR} ${PREFIX}/share/rocksndiamonds
	cd ${WRKSRC} && ${PAX} -r -w sounds graphics levels \
		${PREFIX}/share/rocksndiamonds/
	${CHOWN} -R ${BINOWN}:games ${PREFIX}/share/rocksndiamonds
	${MKDIR} ${SCORE_PATH}/scores
	${CHMOD} 755 ${SCORE_PATH}
	${CHMOD} 775 ${SCORE_PATH}/scores
.for directory in classic_boulderdash classic_emerald_mine \
	classic_sokoban classic_supaplex rnd_tutorial \
	rnd_ben_braithwaite rnd_charles_briscoe-smith \
	rnd_gerhard_haeusler rnd_holger_schemel rnd_jan_hubicka \
	rnd_kimball_robinson rnd_kjell_kristiansson \
	rnd_martin_herrmann rnd_pavel_machek rnd_tobias_authmann \
	rnd_visa_hastrup rnd_warwick_allison rnd_stephan_beyer \
	bd_boulderdash_16 bd_boulderdash_2 bd_xbd
		${MKDIR} ${SCORE_PATH}/scores/${directory} \
		&& ${CHMOD} 775 ${SCORE_PATH}/scores/${directory}
.endfor
	${CHOWN} -R ${BINOWN}:games ${SCORE_PATH}

.include "../../mk/bsd.pkg.mk"
