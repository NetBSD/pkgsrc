# $NetBSD: Makefile,v 1.7 2002/02/19 06:25:57 jmc Exp $
#

DISTNAME=		rocksndiamonds-2.0.0
PKGREVISION=		1
CATEGORIES=		games x11
MASTER_SITES=		http://www.artsoft.org/RELEASES/unix/rocksndiamonds/

MAINTAINER=		wiz@netbsd.org
HOMEPAGE=		http://www.artsoft.org/rocksndiamonds/
COMMENT=		Game like Boulderdash, Emerald Mine, or Sokoban with lots of levels

USE_GMAKE=		YES

.if ( ${MACHINE} == "i386" || ${MACHINE} == "prep" || ${MACHINE} == "cats" || \
      ${MACHINE} == "shark" )
MAKE_ENV+=HAVE_JOYSTICK=1
.endif

# if you change SCORE_PATH, don't forget to change patch-aa, too
SCORE_PATH=		/var/games/rocksndiamonds

do-install:
	${INSTALL_PROGRAM} -o games -g games -m 2755 \
		${WRKSRC}/rocksndiamonds ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/rocksndiamonds.1 ${PREFIX}/man/man1/
	${INSTALL_DATA_DIR} ${PREFIX}/share/rocksndiamonds
	cd ${WRKSRC} && ${PAX} -r -w sounds graphics levels \
		${PREFIX}/share/rocksndiamonds/
	${CHOWN} -R games:games ${PREFIX}/share/rocksndiamonds
	${INSTALL_DATA_DIR} ${SCORE_PATH}/scores
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
		${INSTALL_DATA_DIR} ${SCORE_PATH}/scores/${directory} \
		&& ${CHMOD} 775 ${SCORE_PATH}/scores/${directory}
.endfor
	${CHOWN} -R games:games ${SCORE_PATH}

.include "../../mk/bsd.pkg.mk"
