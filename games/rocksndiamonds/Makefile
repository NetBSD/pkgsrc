# $NetBSD: Makefile,v 1.52 2017/09/09 07:10:34 adam Exp $

DISTNAME=	rocksndiamonds-4.0.0.2
CATEGORIES=	games
MASTER_SITES=	http://www.artsoft.org/RELEASES/unix/rocksndiamonds/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.artsoft.org/rocksndiamonds/
COMMENT=	Game like Boulder Dash, Emerald Mine, or Sokoban
LICENSE=	gnu-gpl-v2

USE_GAMESGROUP=		yes
USE_TOOLS+=		gmake

INSTALLATION_DIRS+=	bin

BUILD_DEFS+=		VARBASE SCORE_PATH
BUILD_DIRS=		src

SHARESUBDIR=		share/rocksndiamonds
SHAREDIR=		${PREFIX}/${SHARESUBDIR}
SCORE_PATH=		${VARBASE}/games/rocksndiamonds
REQD_DIRS+=		${SHARESUBDIR}

OWN_DIRS_PERMS+=	${SCORE_PATH:Q}
OWN_DIRS_PERMS+=	${GAMES_USER} ${GAMES_GROUP} ${GAMEDIRMODE}
OWN_DIRS_PERMS+=	${SCORE_PATH:Q}/scores
OWN_DIRS_PERMS+=	${GAMES_USER} ${GAMES_GROUP} 750
OWN_DIRS_PERMS+=	${SCORE_PATH:Q}/scores/classic_boulderdash
OWN_DIRS_PERMS+=	${GAMES_USER} ${GAMES_GROUP} ${GAMEDIRMODE}
OWN_DIRS_PERMS+=	${SCORE_PATH:Q}/scores/classic_emerald_mine
OWN_DIRS_PERMS+=	${GAMES_USER} ${GAMES_GROUP} ${GAMEDIRMODE}
OWN_DIRS_PERMS+=	${SCORE_PATH:Q}/scores/classic_sokoban
OWN_DIRS_PERMS+=	${GAMES_USER} ${GAMES_GROUP} ${GAMEDIRMODE}
OWN_DIRS_PERMS+=	${SCORE_PATH:Q}/scores/classic_supaplex
OWN_DIRS_PERMS+=	${GAMES_USER} ${GAMES_GROUP} ${GAMEDIRMODE}
OWN_DIRS_PERMS+=	${SCORE_PATH:Q}/scores/rnd_tutorial_aaron_davidson
OWN_DIRS_PERMS+=	${GAMES_USER} ${GAMES_GROUP} ${GAMEDIRMODE}
OWN_DIRS_PERMS+=	${SCORE_PATH:Q}/scores/rnd_tutorial_niko_boehm
OWN_DIRS_PERMS+=	${GAMES_USER} ${GAMES_GROUP} ${GAMEDIRMODE}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Darwin"
SPECIAL_PERMS=		bin/rocksndiamonds ${SETGID_GAMES_PERMS}
.endif

PLIST_SRC=	PLIST ${WRKDIR}/PLIST.F

.if (${MACHINE} == "i386" || ${MACHINE} == "prep" || ${MACHINE} == "cats" || \
      ${MACHINE} == "shark")
MAKE_FLAGS+=	JOYSTICK=-DHAVE_JOYSTICK
.endif

MAKE_FLAGS+=	RO_GAME_DIR=${PREFIX}/share/rocksndiamonds
MAKE_FLAGS+=	RW_GAME_DIR=${SCORE_PATH:Q}
MAKE_FLAGS+=	TARGET=sdl2

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rocksndiamonds ${DESTDIR}${PREFIX}/bin/
	# auto-generated PLIST
	rm -f ${WRKDIR}/PLIST.F
	${RUN} cd ${WRKSRC} && for d in sounds graphics levels music; do \
		find "$${d}" -type d -print | while read s; do \
			${INSTALL_DATA_DIR} ${DESTDIR}${SHAREDIR}/"$${s}"; \
		done; \
		find "$${d}" -type f -print | while read f; do \
			${INSTALL_DATA} "$${f}"	${DESTDIR}${SHAREDIR}/"$${f}"; \
			${ECHO} ${SHARESUBDIR}/"$${f}" >> ${WRKDIR}/PLIST.F; \
		done; \
	done

.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../net/SDL2_net/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
